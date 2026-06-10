int ledPin = 13;
unsigned long startTime; // Stores the exact time the light turned on
unsigned long endTime;   // Stores the exact time you responded
bool gameActive = false;
bool lightIsOn = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
  
  // Reseed the random number generator using noise from an empty pin
  randomSeed(analogRead(0)); 
  
  Serial.println("=== ARDUINO REACTION TEST ===");
  Serial.println("Type 'start' to begin...");
}

void loop() {
  // 1. Wait for the user to start the game
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();

    if (command == "start" && !gameActive) {
      Serial.println("\nGet ready...");
      digitalWrite(ledPin, LOW);
      
      // Pick a random delay between 2 and 5 seconds
      delay(random(2000, 5000)); 
      
      // TURN THE LIGHT ON!
      digitalWrite(ledPin, HIGH);
      startTime = millis(); // Record the starting time in milliseconds
      lightIsOn = true;
      gameActive = true;
      Serial.println("NOW! Type 'off' and hit Enter!");
      
      // Clear any accidental keystrokes sent during the waiting period
      while(Serial.available() > 0) { Serial.read(); } 
    }
    
    // 2. Check the user's reaction
    else if (command == "off" && lightIsOn) {
      endTime = millis(); // Record the stop time
      digitalWrite(ledPin, LOW); // Turn off the light
      
      // Calculate total reaction time
      unsigned long score = endTime - startTime; 
      
      Serial.print("🎯 STOPED! Your reaction time: ");
      Serial.print(score);
      Serial.println(" ms");
      
      // Give a quick rating based on score
      if (score < 250) {
        Serial.println("🏆 Godlike reflexes!");
      } else if (score < 400) {
        Serial.println("👍 Pretty solid!");
      } else {
        Serial.println("🐢 Wake up, sleepyhead!");
      }
      
      // Reset for next game
      gameActive = false;
      lightIsOn = false;
      Serial.println("\nType 'start' to play again.");
    }
  }
}
