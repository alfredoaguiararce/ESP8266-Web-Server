#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "****";    // WiFi network name
const char* password = "****"; // WiFi password

ESP8266WebServer server(80);  // Create a web server on port 80

// Handling the root endpoint
void handleRoot() {
  // Prepare a response for the root endpoint
  String response = "{\"message\": \"Hola desde ESP8266\"}";
  server.send(200, "application/json", response); // Send response with HTTP status 200
}

// Handling a custom endpoint
void handleCustomEndpoint() {
  // Prepare a response for the custom endpoint
  String response = "{\"message\": \"Este es un endpoint personalizado\"}";
  server.send(200, "application/json", response); // Send response with HTTP status 200
}

// Handling when the requested route is not found
void handleNotFound() {
  // Prepare an error response for a non-existing route
  String response = "{\"error\": \"Ruta no encontrada\"}";
  server.send(404, "application/json", response); // Send response with HTTP status 404
}

// Handling POST requests
void handlePostRequest() {
  if (server.hasArg("plain")) {
    // If the POST request contains data
    String postMessage = server.arg("plain");
    // Prepare a response with the received POST data
    String response = "{\"message\": \"Datos recibidos: " + postMessage + "\"}";
    server.send(200, "application/json", response); // Send response with HTTP status 200
  } else {
    // If POST request has no data
    String response = "{\"error\": \"Falta el cuerpo de la solicitud\"}";
    server.send(400, "application/json", response); // Send response with HTTP status 400
  }
}

void setup() {
  Serial.begin(115200); // Initialize serial communication for debugging

  WiFi.begin(ssid, password); // Connect to the WiFi network

  // Wait for WiFi connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando al WiFi...");
  }

  Serial.println("Conectado al WiFi");
  Serial.println("Dirección IP: ");
  Serial.println(WiFi.localIP()); // Print the IP address of the device

  // Define server endpoints and their respective handling functions
  server.on("/", HTTP_GET, handleRoot);
  server.on("/custom", HTTP_GET, handleCustomEndpoint);
  server.on("/post", HTTP_POST, handlePostRequest);
  server.onNotFound(handleNotFound); // Handler for not found routes

  server.begin(); // Start the server
  Serial.println("Servidor HTTP iniciado"); // Print server initialization message
}

void loop() {
  server.handleClient(); // Continuously handle incoming client requests
}
