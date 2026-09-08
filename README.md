# COMPAKT-Reaction-Time-Game

A portable and compact reaction time game with an LCD using **5 LEDs and a pushbutton**.

---

## 🚀 How It Works

4 Green LEDs surrounding the center LED randomly flash until the center Red LED turns on. User must press pushbutton when the Red LED turns on ASAP for their real reaction time. Reaction Time is measured from when the Red LED is turned on to when the button is pressed. User then sees their reaction time on the LCD and an option to play again. The Anti-Cheat System works by checking if the button is pressed at intervals and if it is, the system will increase Cheat Score by 1 and if cheat score exceeds the threshold, cheating will be detected. The most significant feature here is compactibility, where we were able to fit many components onto one breadboard.

### Hardware
- **Development Board:** Arduino Nano
- **Main Components:** LCD + 5 LEDs
- **Software:** Arduino IDE

### Cool Features
- LCD showing reaction time
- COMPAKT-ness
- Anti-Cheat
- Portability
- Dev-Cheat {Time displayed on LCD is randomly picked between 2 numbers you set no matter your actual reaction time; boundaries adjustable; for when you play}
- Dev-Rig {Time displayed on LCD is actually more than actual reaction time; amount adjustable; for when you hand it off to your friend}

---

## 📊 Circuit Layouts

### Wiring Diagram

Below is the wiring diagram for the project:

![Wiring Diagram](COMPAKT_Reaction_Time_Game_Wiring_Diagram.png)

**Note: This wiring diagram was made in Wokwi. Since Wokwi doesn't have a Power MB V2 and some components actually differ from the actual build, the wiring diagram is an approximation of the physical build but retains the correct wiring and functionality.**

### Schematic

Below is the schematic generated in Tinkercad:

[![Schematic](Schematic.png)](Schematic.png)

*Schematic coming soon*

## 🔗 Wokwi Simulation
Try the interactive simulation of the project here:

[Open in Wokwi](https://wokwi.com/projects/474481508287527937)

---
## 🖼️ Project Photo

See the project (may have some issues viewing it on desktop):

[Click here](Reaction_Time_Game_Image.png)

## 🎥 Video Demonstration

Watch the project in action + an explanation of the build:

[▶ Watch the Video](https://youtu.be/86yE3Nd00Po)

---

## 📁 Repository Contents

- `React_Time_Game_COMPAKT.ino` — Arduino source code
- `README.md` — Project documentation
- `LICENSE` — Apache License 2.0
- `Reaction_Time_Game_Image.png` — Project photo
- `COMPAKT_Reaction_Time_Game_Wiring_Diagram.png` — Wiring Diagram 
- `Schematic.png` — Coming Soon!

---

## 🛠️ Components Used

- Arduino Nano Board
- Liquid Crystal Display (LCD)
- Active Buzzer
- 5 LEDs
- 5 Resistors
- Pushbutton
- Power MB V2 + 9V Battery
- Potentiometer
- Jumper wires

---

## 💡 What I Learned

I learned to make my projects more compact. Since I put this project all on **one singular breadboard**, I believe this project has challenged my ability to fit more things onto one breadboard to maximize compactness and capability. I also learned that the metal parts of the resistors must not touch each other for safety and functionality.

---

## 📜 License

This project is licensed under the Apache License 2.0.
