#include <bits/stdc++.h>
#define ll long long
#define mll 2147483647
#define mod 1e9 + 7
#define en '\n'
using namespace std;


bool comp(pair<ll, ll> a, pair<ll, ll> b)
{
    return max(a.first, a.second) < max(b.first, b.second);
}

void solve()
{
    ll k, m, n;
    cin >> k >> m >> n;

    vector<pair<ll, ll>> patches(k);
    for (ll i = 0; i < k; i++)
    {
        ll x, y;
        cin >> x >> y;
        patches[i] = {x, y};
    }

    sort(patches.begin(), patches.end());

    vector<ll> bad_cows(m);

    for (ll i = 0; i < m; i++)
    {
        cin >> bad_cows[i];
    }

    sort(bad_cows.begin(), bad_cows.end());

    vector<ll> max_partials;
    vector<ll> fulls;
    
    vector<pair<ll, ll>> cur;
    ll cur_start = -mll;
    ll patches_ind = 0;
    ll cow_ind = 0;

    while (patches_ind < k or cow_ind < m)
    {
        if (cow_ind >= m or (patches_ind < k and patches[patches_ind].first < bad_cows[cow_ind]))
        {
            if (patches[patches_ind].first != cur_start)
            {
                cur.push_back(patches[patches_ind]);
            }
            patches_ind++;
        }
        else 
        {
            if (cur.size() != 0)
            {
                // calculate max one cow and max two cow
                ll max_two = 0;
                
                map<ll, ll> starts;
                map<ll, ll> ends;
                
                for (pair<ll, ll> item : cur)
                {
                    max_two += item.second;

                    ll ind = max(cur_start + 1, item.first - (bad_cows[cow_ind] - item.first - 1));
                    starts[ind] += item.second;

                    ind = min(bad_cows[cow_ind] - 1, item.first + (item.first - cur_start - 1));

                    ends[ind] += item.second;
                }
                fulls.push_back(max_two);

                vector<pair<ll, ll>> startsv;
                vector<pair<ll, ll>> endsv;

                for (auto item : starts)
                {
                    startsv.push_back({item.first, item.second});
                }

                for (auto item : ends)
                {
                    endsv.push_back({item.first, item.second});
                }


                ll ptr1 = 0;
                ll ptr2 = 0;
                ll max_amount = 0;
                ll cur_amount = 0;
                while (ptr1 < startsv.size() and ptr2 < endsv.size())
                {
                    if (startsv[ptr1].first <= endsv[ptr2].first)
                    {
                        cur_amount += startsv[ptr1].second;
                        max_amount = max(max_amount, cur_amount);
                        ptr1++;
                    }
                    else if (endsv[ptr2].first <= startsv[ptr1].first)
                    {
                        cur_amount -= endsv[ptr2].second;
                        ptr2++;
                    }
                }

                max_partials.push_back(max_amount);
            }



            cur_start = bad_cows[cow_ind];

            cow_ind++;
            cur.clear();
        }
    }

    if (cur.size() != 0)
    {
        ll max_ans = 0;
        for (ll i = 0; i < cur.size(); i++)
        {
            max_ans += cur[i].second;
        }
        fulls.push_back(max_ans);
        max_partials.push_back(max_ans);
    }

    // for (auto item : max_partials)
    // {
    //     cout << item << " ";
    // }

    // cout << endl;
    // for (auto item : fulls)
    // {
    //     cout << item << " ";
    // }

    vector<pair<ll, ll>> finals;
    for (ll i = 0; i < max_partials.size(); i++)
    {
        finals.push_back({max_partials[i] * 2, fulls[i]});
    }

    sort(finals.begin(), finals.end(), comp);
    vector<ll> final2;

    ll ans = 0;
    for (ll i = finals.size() - 1; i >= 0; i--)
    {
        if (finals[i].first > finals[i].second and n > 0)
        {
            ans += finals[i].first / 2;
            n -= 1;
            final2.push_back(finals[i].second - finals[i].first / 2);
            
        }
        else if (n > 1)
        {
            ans += finals[i].first;
            n -= 2;
        }
        else
        {
            final2.push_back(finals[i].first);
        }
    }



    sort(final2.begin(), final2.end());

    for (ll i = final2.size() - 1; i >= 0 and n > 0; i--, n--)
    {
        cout << final2[i] << endl;
        ans += final2[i];
    }

    cout << ans << endl;
    


}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
