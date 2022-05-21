import requests
from bs4 import BeautifulSoup


def main():
    url = 'https://shadowverse-evolve.com/cardlist/cardsearch/?expansion=SD01&view=text&sort=no'
    r = requests.get(url)
    soup = BeautifulSoup(r.text, 'html.parser')
    data_ul = soup.find_all('ul', attrs={'class': 'cardlist-Result_List'})[0]
    for li in data_ul.find_all("li"):
        # print(li)
        name = li.find('img')['alt']
        card_id = li.find('p', attrs={'class': 'number'}).contents[0]

        print(name, card_id)


if __name__ == "__main__":
    main()
