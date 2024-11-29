from pytube import YouTube

def baixar_audio(url):
    try:
        # Cria um objeto YouTube a partir da URL
        yt = YouTube(url)
        
        # Seleciona a melhor stream de áudio disponível
        audio_stream = yt.streams.filter(only_audio=True).first()
        
        # Baixa o áudio na pasta atual
        audio_stream.download(filename=f"{yt.title}.mp3")
        
        print(f"Áudio '{yt.title}' baixado com sucesso!")
    except Exception as e:
        print("Ocorreu um erro:", e)

# Exemplo de uso
url_video = input("Digite a URL do vídeo do YouTube: ")
baixar_audio(url_video)
