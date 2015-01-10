import pygame
from pygame.locals import *
from libpy import RGBcolor as RGB
from libpy import lena
import numpy as np

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


pygame.init()
pygame.display.set_caption('lena')

size = (512, 512)

lena = lena()
lane = np.zeros([512, 512, 3], dtype=int)
lane[:, :, :] = lena[:, :, np.newaxis]

screen = pygame.display.set_mode(lane.shape[:2], 0, 32)
#surface = pygame.Surface([512, 512])
surfarray.blit_array(screen, array_img)

#pygame.Surface.blit(lane, surface)
#surface = pygame.surfarray.make_surface(lena)
#pygame.surfarray.blit_array(surface, lane)
#background = pygame.Surface(screen.get_size())
#background.fill(RGB.Gray)


#screen.blit(surface, (0, 0))
looping = True
while looping:
    pygame.display.flip()
    event = pygame.event.poll()
    looping = quit(event)
