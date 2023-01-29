import speech_recognition as sr


def main():


    # obtem audio pelo microfone
    r = sr.Recognizer()
    with sr.Microphone() as source:
        r.adjust_for_ambient_noise(source)

        #os prints a seguir sao dados para debug do código, somente.
        print("Fale para o jarvis:")
        audio = r.listen(source) # reconhecer a fala
        print("Reconhecendo.... ")


         

        try:
            saveFile = r.recognize_google(audio) #salvar oq foi dito em uma variavel
            print("You have said \n" + r.recognize_google(audio)) #debug
            print("Audio Recorded Successfully \n ")
            with open("temporary.txt", "w") as f:  # escrever oq foi dito no arquivo temporário
                f.write(saveFile)


        except Exception as e: 
            print("Error :  " + str(e))




       


if __name__ == "__main__":
    main()