import pygame

white = (255,255,255)
red = (255,0,0)
black = (0,0,0)
pygame.init()
size = [340,270]
screen = pygame.display.set_mode(size)
pygame.display.set_caption("Ex Pygame")

gameExit = False
lead_X = 50
lead_Y = 50

while not gameExit:
    for event in pygame.event.get():
        #print(event)
        
        if event.type == pygame.QUIT:
            gameExit = True
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT or event.key == pygame.K_a:
                lead_X -= 10
            if event.key == pygame.K_RIGHT or event.key == pygame.K_d:
                lead_X += 10
            if event.key == pygame.K_UP or event.key == pygame.K_w:
                lead_Y -= 10
            if event.key == pygame.K_DOWN or event.key == pygame.K_s:
                lead_Y += 10
            if event.key == pygame.K_ESCAPE:
                exit()
        screen.fill(white)
        pygame.draw.rect(screen,red,[lead_X,lead_Y,5,5])
        pygame.display.flip()
        
pygame.quit()
quit()