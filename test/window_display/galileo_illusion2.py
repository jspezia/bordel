import pygame
from libpy import RGBcolor as RGB

def galileo(color1, color2):
	pygame.draw.rect(screen, color1, pygame.Rect(0, 0, 450, 450))
	pygame.draw.rect(screen, color2, pygame.Rect(450, 0, 450, 450))

def cubedraw(color, x, y):
	pygame.draw.rect(screen, color, pygame.Rect(x, y, 150, 150))


class cube:
	def __init__(self, x, y):
		self.x = x
		self.y = y

color1 = RGB.Black
color2 = RGB.White

pygame.init()
screen = pygame.display.set_mode((900, 450))
done = False
cube1 = cube(150, 150)
cube2 = cube(600, 150)
clock = pygame.time.Clock()
while not done:
	galileo(color1, color2)
	cubedraw(color2, cube1.x, cube1.y)
	cubedraw(color1, cube2.x, cube2.y)
	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			done = True
		if event.type == pygame.KEYDOWN and event.key == pygame.K_SPACE:
			color3 = color1
			color1 = color2
			color2 = color3
	pressed = pygame.key.get_pressed()
	if pressed[pygame.K_a] and cube1.x > 0: cube1.x -= 3
	if pressed[pygame.K_d] and cube1.x < 300: cube1.x += 3
	if pressed[pygame.K_w] and cube1.y > 0: cube1.y -= 3
	if pressed[pygame.K_s] and cube1.y < 300: cube1.y += 3
	if pressed[pygame.K_LEFT] and cube2.x > 450: cube2.x -= 3
	if pressed[pygame.K_RIGHT] and cube2.x < 750: cube2.x += 3
	if pressed[pygame.K_UP] and cube2.y > 0: cube2.y -= 3
	if pressed[pygame.K_DOWN] and cube2.y < 300: cube2.y += 3
	clock.tick(60)
	pygame.display.flip()
