import pygame
from pygame.locals import *
from libpy import RGBcolor as RGB
import numpy as np

import sys, os
from pygame import surfarray

def quit(event):
    _continue = True
    if event.type == QUIT:
        _continue = False
    if (event.type == KEYDOWN) and (event.key == K_ESCAPE):
        _continue = False
    if _continue == False:
        import sys
        pygame.quit()
        sys.exit()
    return(_continue)


surfarray.use_arraytype('numpy')


h = 256
w = 256
f = 128

pygame.init()
pygame.display.set_caption('lena')

import MotionClouds as mc
fx, fy, ft = mc.get_grids(h, w, f)

color = mc.envelope_color(fx, fy, ft)
env = color * mc.envelope_speed(fx, fy, ft, V_X=0.5)
#env = color * mc.envelope_gabor(fx, fy, ft)
env = mc.random_cloud(env, seed=123456)

stimulus = np.zeros([f, h, w, 3], dtype=int)

screen = pygame.display.set_mode((h, w), RESIZABLE)

surface = pygame.Surface(stimulus.shape[1:3])

stimulus[:, :, :, :] = 0

print env

i = 0
j = 0
k = 0

white = (250, 230, 210, 190, 170, 150)
blue = (0, 20, 40, 60, 80, 100, 120)

print min(env[0, 1, :])
print min(env[12, 23, :])
print max(env[2, 32, :])
print max(env[42, 42, :])

a = 0.0001
b = 0.0001

while (i != f):
    while (j != h):
        while (k != w):
            if (env[j, k, i] > 0):
                if (env[j, k, i] > a*10): stimulus[i, j, k, :] = white[0]
                elif (env[j, k, i] > a*8): stimulus[i, j, k, :] = white[1]
                elif (env[j, k, i] > a*6): stimulus[i, j, k, :] = white[2]
                elif (env[j, k, i] > a*4): stimulus[i, j, k, :] = white[3]
                elif (env[j, k, i] > a*2): stimulus[i, j, k, :] = white[4]
                else: stimulus[i, j, k, :] = white[5]
#                stimulus[i, j, k, 0] = 255#128 + env[j, k, i] * 30000
#                stimulus[i, j, k, 1] = 255#128 + env[j, k, i] * 30000
            else:
                stimulus[i, j, k, 2] = 255
                if (env[j, k, i] < -b*10): stimulus[i, j, k, :2] = blue[0]
                elif (env[j, k, i] < -b*8): stimulus[i, j, k, :2] = blue[1]
                elif (env[j, k, i] < -b*6): stimulus[i, j, k, :2] = blue[2]
                elif (env[j, k, i] < -b*4): stimulus[i, j, k, :2] = blue[3]
                elif (env[j, k, i] < -b*2): stimulus[i, j, k, :2] = blue[4]
                else: stimulus[i, j, k, 0:1] = blue[5]
            k += 1
        k = 0
        j += 1
    j = 0
    i += 1


looping = True
i = 0
while looping:
    if (i == f): i = 0
    surfarray.blit_array(surface, stimulus[i])
    screen.blit(surface, (0, 0))
    pygame.display.flip()
    event = pygame.event.poll()
    looping = quit(event)
    i += 1
