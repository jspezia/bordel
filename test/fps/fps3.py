#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import print_function, division
import pygame
from libpy import RGBcolor as RGB
import time

def epilept(color1):
    pygame.draw.rect(screen, color1, pygame.Rect(0, 0, 450, 450))


class cube:
    def __init__(self, x, y):
        self.x = x
        self.y = y

color1 = RGB.Black
color2 = RGB.White


pygame.init()
screen=pygame.display.set_mode((450, 450))
background = pygame.Surface(screen.get_size())
clock = pygame.time.Clock()

cube1 = cube(150, 150)

epilept(color1)
i = 0
t0 = time.time()
while (i != 300):
    epilept(color2)
    pygame.display.flip()
    epilept(color1)
    pygame.display.flip()
    i += 1
pygame.display.flip()
t1 = time.time()
t_total = t1 - t0
fps = 600 / t_total
print ('t_total = ')
print (t_total)
print ('fps = ')
print (fps)
pygame.quit()
