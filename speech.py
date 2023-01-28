import speech_recognition as sr


def main():

    r = sr.Recognizer()

    with sr.Microphone() as source:
        r.adjust_for_ambient_noise(source)

        print("Fale para o jarvis:")

        audio = r.listen(source)

        print("Reconhecendo.... ")


        # reconhecer a fala e escrever em um arquivo de texto

        try:
            saveFile = r.recognize_google(audio)
            print("You have said \n" + r.recognize_google(audio))
            print("Audio Recorded Successfully \n ")
            with open("temporary.txt", "w") as f:  # escrever oq foi dito no arquivo temporário
                f.write(saveFile)


        except Exception as e:
            print("Error :  " + str(e))




       


if __name__ == "__main__":
    main()