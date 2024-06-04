#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <vector>
struct cmp {
    bool operator()(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
        if (a.second == b.second)
            return a.first.compare(b.first) < 0;
        return a.second < b.second;
    };
};
std::map<std::string, int> myMap;
int main() {
    std::ifstream f;
    f.open("text.txt");
    std::string propozitie;
    std::getline(f, propozitie);
    int n = propozitie.length(),k=0;
    for (int i = 0;i < n;i++)
        if (propozitie[i] != ' ' && propozitie[i] != ',' && propozitie[i] != '?' && propozitie[i] != '!' && propozitie[i] != '.')
        {
            int ok = 1;
            int j = i;
            std::string cuvant;
            while (ok&&j<n) {
                if (propozitie[j] != ' ' && propozitie[j] != ',' && propozitie[j] != '?' && propozitie[j] != '!' && propozitie[j] != '.')
                {
                    if (propozitie[j] <= 'Z')
                        propozitie[j] += (int)('a' - 'A');
                    cuvant += propozitie[j];
                    ++j;
                }
                else
                    ok = 0;
            }
            j -= i;
            myMap[cuvant] = j;
            i += j;
            k++;
        }
    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, cmp> coada;
    for (auto iter = myMap.begin(); iter != myMap.end(); ++iter)
    {
        std::pair<std::string, int> a;
        a.first = iter->first;
        a.second = iter->second;
        coada.push(a);
    }
    while (!coada.empty()) {
        std::pair<std::string, int> top = coada.top();
        std::cout << top.first << " => " << top.second << std::endl;
        coada.pop();
    }
    return 0;
}
















































/*struct cmp {
    bool operator()(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
        if (a.second == b.second)
            return a.first.compare(b.first) > 0;
        return a.second < b.second;
    };
};



int main() {
    std::ifstream f;
    f.open("text_file.txt");

    std::string sentence;
    std::getline(f, sentence);
    std::transform(sentence.begin(), sentence.end(), sentence.begin(),
        [](unsigned char c) { return std::tolower(c); });
    std::map<std::string, int> map;

    // SPLIT INTO WORDS
    std::size_t prev = 0, pos;
    std::string word;
    while ((pos = sentence.find_first_of(" .,?!", prev)) != std::string::npos) {
        int count = 0;
        if (pos > prev) {
            int poss = sentence.find(word, 0);
            while (poss != std::string::npos) {
                ++count;
                poss = sentence.find(word, poss + 1);
            }
            word = sentence.substr(prev, pos - prev);

            if (word.size() != 0)
                map[word] = count;
        }
        prev = pos + 1;
    }


    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, cmp> pq;

    for (auto iter = map.begin(); iter != map.end(); ++iter)
    {
        std::pair<std::string, int> p;
        p.first = iter->first;
        p.second = iter->second;
        pq.push(p);
    }

    while (!pq.empty()) {
        std::pair<std::string, int> top = pq.top();
        std::cout << top.first << " => " << top.second << std::endl;
        pq.pop();
    }

    return EXIT_SUCCESS;
}*/