import speech_recognition as sr


def main():

    r = sr.Recognizer()

    with sr.Microphone() as source:
        r.adjust_for_ambient_noise(source)

        print("Fale para o jarvis:")

        audio = r.listen(source)

        print("Reconhecendo.... ")


        # recognize speech using google

        try:
            saveFile = r.recognize_google(audio)
            print("You have said \n" + r.recognize_google(audio))
            print("Audio Recorded Successfully \n ")
            with open("botLearning.txt", "a") as f:
                f.write("\n"+saveFile+":")


        except Exception as e:
            print("Error :  " + str(e))




        # write audio
        with open("recorded.wav", "wb") as f:
            f.write(audio.get_wav_data())


if __name__ == "__main__":
    main()