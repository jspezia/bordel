#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import print_function, division
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
screen=pygame.display.set_mode((900, 450))
background = pygame.Surface(screen.get_size())
clock = pygame.time.Clock()

cube1 = cube(150, 150)
cube2 = cube(600, 150)

galileo(color1, color2)
cubedraw(color2, cube1.x, cube1.y)
cubedraw(color1, cube2.x, cube2.y)

mainloop = True
FPS = 50
playtime = 0.0

pygame.display.flip()
while mainloop:
    pygame.display.flip()
    milliseconds = clock.tick(FPS)
    playtime += milliseconds / 1000.0

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            mainloop = False
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_ESCAPE:
                mainloop = False

    text = "FPS: {0:.2f}   Playtime: {1:.2f}".format(clock.get_fps(), playtime)
    pygame.display.set_caption(text)
#    pygame.display.flip()

pygame.quit()

# At the very last:
print("This game was played for {0:.2f} seconds".format(playtime))
