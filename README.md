# **ESP8266 Web Server**

This project sets up a basic web server on an ESP8266 microcontroller using the Arduino framework. The web server responds to specific endpoints with JSON data for GET and POST requests.

## **Description**

The code initializes a web server on an ESP8266 microcontroller and defines various endpoints to handle incoming HTTP requests. It responds with JSON data and provides different functionalities based on the requested endpoints.

## **Prerequisites**

To run this code, you'll need:

- Arduino IDE installed
- ESP8266 board support installed on the Arduino IDE
- ESP8266WiFi library
- ESP8266WebServer library

## **Setup**

1. Open the code in the Arduino IDE.
2. Set your Wi-Fi network credentials by modifying the **`ssid`** and **`password`** variables.
3. Upload the code to your ESP8266 board.
4. Open the Serial Monitor to view the output and obtain the IP address once the ESP8266 is connected to the Wi-Fi network.

## **Usage**

- Access the root endpoint at **`http://<ESP8266_IP>/`** to receive a greeting message.
- Visit **`http://<ESP8266_IP>/custom`** for a custom endpoint response.
- Send a POST request to **`http://<ESP8266_IP>/post`** with the desired content to receive a formatted response.

## **Endpoint Details**

- **Root Endpoint**: **`/`** (HTTP GET)
    - Responds with a greeting message.
- **Custom Endpoint**: **`/custom`** (HTTP GET)
    - Provides a response specific to this endpoint.
- **POST Endpoint**: **`/post`** (HTTP POST)
    - Receives data and responds with a formatted message acknowledging the received content.

## **Additional Notes**

- Ensure your ESP8266 is connected to the specified Wi-Fi network for the server to function properly.
- Error handling is included for cases where the requested route is not found or when there's no data in a POST request.

## **Contributions**

Contributions to improve and expand this basic ESP8266 web server code are welcome. Please feel free to fork this repository, make your changes, and submit a pull request.

## **License**

This project is licensed under the MIT License. See the [LICENSE](https://chat.openai.com/c/LICENSE) file for details.