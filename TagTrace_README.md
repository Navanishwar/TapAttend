# TagTrace – RFID Attendance System Using Arduino

TagTrace is an automated attendance system that utilizes RFID technology and the Arduino platform. This system continuously scans RFID tags and logs attendance by capturing unique tag numbers (UIDs). It is designed to provide a reliable and efficient solution for attendance tracking in schools, colleges, and workplaces.

## Features
- **Real-time RFID UID Detection**: Continuously scans for RFID tags and logs the UID.
- **Time Interval Management**: Avoids redundant detections by implementing customizable time intervals.
- **Easy Integration**: Can be integrated with existing systems for automated attendance tracking.
- **Low Power Consumption**: Optimized for minimal energy usage, making it suitable for long-term deployments.

## How It Works
1. The RFID reader continuously monitors for the presence of RFID cards.
2. Once a card is detected, the UID is read and displayed in the Serial Monitor.
3. The system records the UID and updates the attendance records.
4. If no card is detected for a set interval, the system resets the card detection status.

## Hardware Requirements
- Arduino UNO
- MFRC522 RFID Reader
- RFID Tags
- Breadboard and jumper wires


