#https://www.youtube.com/watch?v=SqvVm3QiQVk&t=37s
import requests
from bs4 import BeautifulSoup as bs

githubUser = input("Input Github User: ")

url = 'https://github.com/' + githubUser
r = requests.get(url)
soup = bs(r.content, 'html.parser')

profile_image = soup.find('img', {'alt' : 'Avatar'})['src']
print(profile_image)
space = input("")