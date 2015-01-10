import pygame
from libpy import RGBcolor as RGB

pygame.init()
screen = pygame.display.set_mode((900, 450))
done = False

def galileo(color1, color2):
	pygame.draw.rect(screen, color1, pygame.Rect(0, 0, 450, 450))
	pygame.draw.rect(screen, color2, pygame.Rect(450, 0, 450, 450))
	pygame.draw.rect(screen, color2, pygame.Rect(150, 150, 150, 150))
	pygame.draw.rect(screen, color1, pygame.Rect(600, 150, 150, 150))

color1 = RGB.Black
color2 = RGB.White

while not done:
	galileo(color1, color2)
	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			done = True
		if event.type == pygame.KEYDOWN and event.key == pygame.K_SPACE:
			color3 = color1
			color1 = color2
			color2 = color3
	pygame.display.flip()
