import pygame
from pygame.locals import *
from libpy import RGBcolor as RGB
from libpy import lena
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


#surfarray.use_arraytype('numpy')


#pygame.init()
#pygame.display.set_caption('lena')

from numpy import *

#lena = lena()
#lena = np.rot90(lena, 1)
#lena = np.flipud(lena)
#
#lane = np.zeros([512, 512, 3], dtype=int)
#lane[:, :, :] = lena[:, :, np.newaxis]

import MotionClouds as mc

fx, fy, ft = mc.get_grids(512, 512, 128)
color = mc.envelope_color(fx, fy, ft)
env = color * mc.envelope_speed(fx, fy, ft, V_X=0.5)
#env = mc.envelope_gabor(fx, fy, ft)
#env = mc.random_cloud(env)
env = mc.rectif(env, contrast=1.)
#env = env * 25
#env[:, :, :] = abs(mov[:, :, :] - 255)
print env
#stimulus = np.zeros([512, 512, 3], dtype=int)
#stimulus[:, :, 0] = 128
#stimulus[:, :, 1] = env[:, :, 0]
#stimulus[:, :, 2] = 0

#screen = pygame.display.set_mode(stimulus.shape[:2])#, RESIZABLE)

#surface = pygame.Surface(stimulus.shape[:2])

#surfarray.blit_array(surface, stimulus)

#screen.blit(surface, (0, 0))
looping = True
i = 0
#while looping:
#    if (i == 64): i = 0
#    stimulus[:, :, 1] = env[:, :, i]
#    surfarray.blit_array(surface, stimulus)
#    screen.blit(surface, (0, 0))
#    pygame.display.flip()
#    event = pygame.event.poll()
#    looping = quit(event)
#    i += 1
