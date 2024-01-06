from selenium import webdriver
from selenium.webdriver.chrome.options import Options
import time
chrome_options = Options()
chrome_options.add_argument("--incognito")
chrome_options.add_argument("--window-size=1920x1080")
driver = webdriver.Chrome()
url = "https://news.ycombinator.com/"
driver.get(url)
time.sleep(3)
elements = driver.find_elements_by_css_selector(".storylink")
storyTitles = [el.text for el in elements]
storyUrls = [el.get_attribute("href") for el in elements]
elements = driver.find_elements_by_css_selector(".score")
scores = [el.text for el in elements]
elements = driver.find_elements_by_css_selector(".sitebit a")
sites = [el.get_attribute("href") for el in elements]

print(storyTitles)
print(storyUrls)
print(scores)
print(sites)