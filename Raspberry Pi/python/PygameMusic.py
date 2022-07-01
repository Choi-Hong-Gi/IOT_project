import pygame


mp3File = '/home/pi/Desktop/ending.mp3'

pygame.mixer.init()
pygame.mixer.music.load(mp3File)

print('play')
pygame.mixer.music.play()
while pygame.mixer.music.get_busy() == True:
    continue

print('End Play')

# Usaully use TTS more than mp3.