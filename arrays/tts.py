import pyttsx3

def text_to_speech(text):
    engine = pyttsx3.init()
    engine.setProperty('rate', 175)  # Speed of speech
    engine.setProperty('volume', 1.0)  # Volume 0-1
    engine.say(text)
    engine.runAndWait()

# Example: huge text file
with open("long_text.txt", "r", encoding="utf-8") as f:
    long_text = f.read()

text_to_speech(long_text)
