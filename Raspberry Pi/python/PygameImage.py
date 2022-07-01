import pygame
from pygame.locals import *

black = (0,0,0)
white = (255,255,255)
blue = (0,0,255)
red = (255,0,0)
green = (0,255,0)

pygame.init()
screen = pygame.display.set_mode((840,840))
pygame.display.set_caption("Load Image")
loadImage = pygame.image.load("compass-3.png").convert()
screen.fill(white)

degree = 0
clock = pygame.time.Clock()
FPS = 50

while True:
    rotated = pygame.transform.rotate(loadImage,degree)
    rect = rotated.get_rect()
    rect.center = [420,420]
    screen.blit(rotated, rect)
    pygame.display.flip()
    degree += 3
    if degree > 360:
        degree = 0
    clock.tick(FPS)
    
pygame.quit()