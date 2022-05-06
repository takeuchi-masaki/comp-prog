#include <bits/stdc++.h>
using namespace std;

string link = "https://shadowverse-evolve.com/wordpress/wp-content/images/cardlist/BP01/bp01_";
string suffix = ".png";

struct Card {
	string name, ID, card_class, card_type, cost, stats, trait, rarity;
	string text;
	int haveEvolve = -1;
    vector<string> related;
};

void div(string divName) {
	cout << "<" << divName << ">";
}
void closeDiv(string divName) {
	cout << "</" << divName << ">\n";
}

int main() {
	vector<string> tokenNames;
	{
		ifstream getTokens("tokenList.txt");
		string token;
		while (getline(getTokens, token)) {
			tokenNames.push_back(token);
		}
	}

	ifstream fin("sv_evolve.tsv");
	freopen("out.xml", "w", stdout);
	vector<Card> cardList, evolveList;
	for (int i = 0; i < 180; i++) {
		Card c;
		string s;
		getline(fin, s);
		vector<int> tab;
		for (int j = 0; j < (int)s.size(); j++) {
			if (s[j] == '\t') {
				tab.push_back(j);
			}
		}
		c.name = s.substr(0, tab[0]);
		c.ID = s.substr(tab[0] + 1, tab[1] - tab[0] - 1);
		c.card_class = s.substr(tab[1] + 1, tab[2] - tab[1] - 1);
		c.card_type = s.substr(tab[2] + 1, tab[3] - tab[2] - 1);
		c.cost = s.substr(tab[3] + 1, tab[4] - tab[3] - 1);
		c.stats = s.substr(tab[4] + 1, tab[5] - tab[4] - 1);
		c.trait = s.substr(tab[5] + 1, tab[6] - tab[5] - 1);
		c.rarity = s.substr(tab[6] + 1, tab[7] - tab[6] - 1);

		string ogtext = s.substr(tab[7] + 1);
		for (int j = 0; j < (int)ogtext.size(); j++) {
			char ch = ogtext[j];
			if (ch == '<' || ch == '>') {
				continue;
			}
			if (ch == '&') {
				c.text += "and";
			} else {
				c.text.push_back(ch);
			}
		}

		for (string token: tokenNames) {
            if(c.text.find(token) != string::npos) {
                c.related.push_back(token);
            }
        }

        if (c.name.size() > 9 && c.name.substr(c.name.size() - 9) == "(Evolved)") {
            cardList.back().haveEvolve = evolveList.size();
            evolveList.push_back(c);
        } else {
            cardList.push_back(c);
        }
	}

	for (auto c: cardList) {
		div("card");
		cout << '\n';

		div("name");
		cout << c.name;
		closeDiv("name");

		div("text");
		cout << c.text;
		closeDiv("text");

		div("prop");
		cout << '\n';
		{
			div("layout");
			cout << "normal";
			closeDiv("layout");

			div("side");
			cout << "front";
			closeDiv("side");

			div("type");
			cout << c.card_type;
			closeDiv("type");

			div("maintype");
			cout << c.card_type;
			closeDiv("maintype");

			div("manacost");
			cout << c.cost;
			closeDiv("manacost");

			div("cmc");
			cout << c.cost;
			closeDiv("cmc");

			div("colors");
			cout << c.card_class;
			closeDiv("colors");

			div("coloridentity");
			cout << c.card_class;
			closeDiv("coloridentity");

			div("format-standard");
			cout << "legal";
			closeDiv("format-standard");

			if (c.card_type != "Amulet" && c.card_type != "Spell") {
				div("pt");
				cout << c.stats;
				closeDiv("pt");
			}
		}
		closeDiv("prop");

		cout << "<set rarity=\"" << c.rarity << "\" "
			 << "num=\"" << c.ID.substr(5) << "\" "
			 << "uuid=\"" << c.ID.substr(5) << "\" "
			 << "muid=\"" << c.ID.substr(5) << "\" ";
		cout << "picurl=\"" << link << c.ID.substr(5) << suffix << "\">";
		cout << "BP01</set>\n";

		if (c.haveEvolve >= 0) {
			cout << "<related attach=\"1\">" << evolveList[c.haveEvolve].name;
			closeDiv("related");
		}

        for (string s: c.related) {
            div("related");
            cout << s;
            closeDiv("related");
        }

		div("token");
		cout << "0";
		closeDiv("token");

		div("tablerow");
		if (c.card_type == "Spell") {
			cout << "1";
		} else {
			cout << "2";
		}
		closeDiv("tablerow");

		closeDiv("card");
		cout << '\n';
	}

	for (auto c: evolveList) {
		div("card");
		cout << '\n';

		div("name");
		cout << c.name;
		closeDiv("name");

		div("text");
		cout << c.text;
		closeDiv("text");

		div("prop");
		cout << '\n';
		{
			div("layout");
			cout << "normal";
			closeDiv("layout");

			div("side");
			cout << "front";
			closeDiv("side");

			div("type");
			cout << c.card_type;
			closeDiv("type");

			div("maintype");
			cout << c.card_type;
			closeDiv("maintype");

			div("manacost");
			cout << c.cost;
			closeDiv("manacost");

			div("cmc");
			cout << c.cost;
			closeDiv("cmc");

			div("colors");
			cout << c.card_class;
			closeDiv("colors");

			div("coloridentity");
			cout << c.card_class;
			closeDiv("coloridentity");

			div("format-standard");
			cout << "banned";
			closeDiv("format-standard");

			if (c.card_type != "Amulet" && c.card_type != "Spell") {
				div("pt");
				cout << c.stats;
				closeDiv("pt");
			}
		}
		closeDiv("prop");

		cout << "<set rarity=\"" << c.rarity << "\" "
			 << "num=\"" << c.ID.substr(5) << "\" "
			 << "uuid=\"" << c.ID.substr(5) << "\" "
			 << "muid=\"" << c.ID.substr(5) << "\" ";
		cout << "picurl=\"" << link << c.ID.substr(5) << suffix << "\">";
		cout << "TK</set>\n";

		if (c.haveEvolve >= 0) {
			cout << "<related attach=\"1\">" << evolveList[c.haveEvolve].name;
			closeDiv("related");
		}

		div("token");
		cout << "0";
		closeDiv("token");

		div("tablerow");
		if (c.card_type == "Spell") {
			cout << "1";
		} else {
			cout << "2";
		}
		closeDiv("tablerow");

		closeDiv("card");
		cout << '\n';
	}
	closeDiv("cards");
	closeDiv("cockatrice_carddatabase");
}