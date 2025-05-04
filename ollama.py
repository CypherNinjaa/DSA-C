import requests

# Define the URL for the endpoint
url = "http://localhost:11434/predict"

# Define the data you want to send
data = {
    "text": "Your input text here"
}

# Send a POST request to the endpoint
response = requests.post(url, json=data)

# Check the response
if response.status_code == 200:
    print("Prediction:", response.json())
else:
    print("Error:", response.status_code)