#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     long long dividePlayers(vector<int>& skill) {
//         sort(skill.begin(), skill.end());

//         int n = skill.size();
//         long long totalChemistry = 0;
//         int targetTeamSkill = skill[0] + skill[n - 1];

//         for (int i = 0; i < n / 2; i++) {
//             int currentTeamSkill = skill[i] + skill[n - i - 1];

//             if (currentTeamSkill != targetTeamSkill) {
//                 return -1;
//             }

//             totalChemistry += (long long)skill[i] * (long long)skill[n - i - 1];
//         }

//         return totalChemistry;
//     }
// };

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        int totalSkill = 0;
        unordered_map<int, int> skillMap;

        for (int s : skill) {
            totalSkill += s;
            skillMap[s] = skillMap[s] + 1;
        }

        if (totalSkill % (n / 2) != 0) {
            return -1;
        }

        int targetSkill = totalSkill / (n / 2);
        long long totalChemistry = 0;

        for (auto& [currSkill, currFreq] : skillMap) {
            int partnerSkill = targetSkill - currSkill;

            if (skillMap.find(partnerSkill) == skillMap.end() ||
                currFreq != skillMap[partnerSkill]) {
                return -1;
            }

            totalChemistry += (long long)currSkill * (long long)partnerSkill *
                              (long long)currFreq;
        }
        return totalChemistry / 2;
    }
};