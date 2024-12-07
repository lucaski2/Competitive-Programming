import requests
from bs4 import BeautifulSoup
import gspread
from oauth2client.service_account import ServiceAccountCredentials

# Google Sheets Setup
def setup_google_sheets(sheet_name):
    # Use your credentials JSON file
    scope = ["https://spreadsheets.google.com/feeds", "https://www.googleapis.com/auth/drive"]
    creds = ServiceAccountCredentials.from_json_keyfile_name("credentials.json", scope)
    client = gspread.authorize(creds)

    # Open the Google Sheet (replace with your sheet name)
    sheet = client.open(sheet_name).sheet1
    return sheet

# Scrape USACO Problems
def scrape_usaco_problems():
    url = "http://www.usaco.org/index.php?page=contests"
    response = requests.get(url, headers={"User-Agent": "Mozilla/5.0"})
    
    if response.status_code != 200:
        raise Exception(f"Failed to fetch USACO contests. Status code: {response.status_code}")

    soup = BeautifulSoup(response.content, "html.parser")
    problems = []

    # Find contest table rows
    for row in soup.select("table tr"):
        cols = row.find_all("td")
        if len(cols) >= 4:
            year = cols[0].text.strip()
            contest = cols[1].text.strip()
            division = cols[2].text.strip()
            problem_link = cols[3].find("a")["href"].strip()
            problem_name = cols[3].find("a").text.strip()

            problems.append({
                "Year": year,
                "Contest": contest,
                "Division": division,
                "Problem Name": problem_name,
                "Link": f"http://www.usaco.org/{problem_link}",
                "Status": "Not Started",
                "Notes": ""
            })

    return problems

# Upload to Google Sheets
def upload_to_google_sheets(sheet, problems):
    # Clear existing data
    sheet.clear()

    # Set headers
    headers = ["Problem Name", "Year", "Contest", "Division", "Link", "Status", "Notes"]
    sheet.append_row(headers)

    # Add problems to the sheet
    for problem in problems:
        sheet.append_row([
            problem["Problem Name"],
            problem["Year"],
            problem["Contest"],
            problem["Division"],
            problem["Link"],
            problem["Status"],
            problem["Notes"]
        ])

    print("Problems uploaded to Google Sheets successfully!")

# Main function
def main():
    # Google Sheet name (replace with your own sheet name)
    sheet_name = "USACO Problems"

    try:
        # Setup Google Sheets
        sheet = setup_google_sheets(sheet_name)

        # Scrape USACO problems
        print("Scraping USACO problems...")
        problems = scrape_usaco_problems()
        print(f"Found {len(problems)} problems.")

        # Upload to Google Sheets
        print("Uploading problems to Google Sheets...")
        upload_to_google_sheets(sheet, problems)

    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    main()
