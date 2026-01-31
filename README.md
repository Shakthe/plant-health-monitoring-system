# 🌱 Plant Health Monitoring System

## 📌 Overview

The **Plant Health Monitoring System** is a real-time monitoring application designed to track and visualize environmental conditions affecting plant growth. The system focuses on collecting **soil moisture** and **ambient humidity** data, processing it in real time, and displaying meaningful insights through live dashboards.

This project demonstrates the use of **real-time data pipelines**, **event-driven communication**, and **interactive dashboards** to support informed plant care and irrigation decisions.

---

## 🎯 Objectives

* Monitor soil moisture levels to understand irrigation needs
* Track ambient humidity to assess surrounding environmental conditions
* Enable real-time visualization of sensor data
* Build a scalable and low-latency data communication pipeline
* Provide actionable insights for maintaining plant health

---

## 🛠️ Tech Stack

### Core Technologies

* **MQTT** – Lightweight messaging protocol for real-time data communication
* **Node-RED** – Flow-based development tool for data processing and dashboard creation

### Sensors

* **Soil Moisture Sensor** – Measures water content in the soil
* **Humidity Sensor** – Measures ambient humidity levels

### Additional Tools

* **MQTT Broker** (e.g., Mosquitto) – Manages message exchange between publishers and subscribers
* **Web-based Dashboard** – Displays live sensor readings and trends

---

## 🏗️ System Architecture

1. **Data Collection**

   * Soil moisture and humidity sensors continuously capture environmental data.
   * Sensor readings are published as messages to specific MQTT topics.

2. **Real-Time Communication**

   * MQTT enables efficient, low-overhead transmission of sensor data.
   * Each sensor publishes data at regular intervals.

3. **Data Processing**

   * Node-RED subscribes to MQTT topics.
   * Incoming data is processed, filtered, and structured for visualization.

4. **Visualization & Monitoring**

   * Live dashboards display soil moisture and humidity levels.
   * Graphs and gauges update in real time.

---

## 📊 Features

* Real-time monitoring of soil moisture levels
* Continuous tracking of ambient humidity
* Live dashboards with automatic updates
* Event-driven data handling using MQTT
* Scalable architecture for adding more sensors in the future

---

## 📂 Project Structure

```
plant-health-monitoring-system/
│
├── node-red-flows/
│   └── flows.json        # Node-RED flow configurations
│
├── mqtt/
│   └── topics.md         # MQTT topic structure documentation
│
├── dashboard/
│   └── ui-layout.md      # Dashboard layout and components
│
├── docs/
│   └── architecture.md   # System architecture explanation
│
└── README.md             # Project documentation
```

---

## 📡 MQTT Topic Design

* `plant/soil/moisture` – Publishes soil moisture readings
* `plant/environment/humidity` – Publishes humidity readings

Each message contains:

* Sensor value
* Timestamp
* Sensor identifier

---

## 📈 Dashboard Design

The Node-RED dashboard includes:

* **Gauges** for current soil moisture and humidity levels
* **Line charts** showing historical trends
* **Status indicators** to quickly identify abnormal conditions

The dashboard updates automatically as new data arrives.

---

## 🚀 Setup & Installation

1. Install **Node.js** and **Node-RED**
2. Install and configure an **MQTT broker** (e.g., Mosquitto)
3. Import Node-RED flow files into the Node-RED editor
4. Configure MQTT broker credentials in Node-RED
5. Start the Node-RED server
6. Access the dashboard through the browser

---

## 🔍 Use Cases

* Home gardening and smart plant care
* Greenhouse environment monitoring
* Educational projects for real-time systems and dashboards
* Prototype for smart agriculture applications

---

## 📌 Future Enhancements

* Add temperature and light intensity sensors
* Implement alert notifications for critical conditions
* Store historical data in a database for long-term analysis
* Integrate predictive analytics for irrigation recommendations

---

## 🧠 Key Learnings

* Designing real-time, event-driven systems
* Working with MQTT for low-latency data transfer
* Building interactive dashboards using Node-RED
* Structuring scalable data flows for continuous monitoring

---

## 👤 Author

**Shakthevell M**
B.Tech CSE (IoT Specialization)
Shiv Nadar University Chennai

---

## 📄 License

This project is for educational and academic use.
