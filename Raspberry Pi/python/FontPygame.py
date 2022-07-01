import pygame

black = (0,0,0)
white = (255,255,255)
blue = (0,0,255)
red = (255,0,0)
green = (0,255,0)

pygame.init()
size = [640,480]
screen = pygame.display.set_mode(size)
pygame.display.set_caption("Ex Pygame")

font = pygame.font.SysFont("comicsansms", 72)
text = font.render("Hello Pygame Text", True, (255,0,0))

while True:
    screen.fill(white)
    screen.blit(text, (320-text.get_width()//2,240-text.get_height()//2))
    pygame.display.flip()
    
    