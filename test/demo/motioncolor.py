import numpy as np
import libpy as lb
import sys, os
import MotionClouds as mc

h = 1024
w = 1024
f = 32

fx, fy, ft = mc.get_grids(h, w, f)

color = mc.envelope_color(fx, fy, ft)
env = color * mc.envelope_speed(fx, fy, ft, V_X=0.5)
env = mc.random_cloud(env, seed=123456)

env = mc.rectif(env, contrast=1.)
env = env * 255

stimulus = np.zeros([f, h, w, 3], dtype=int)

#stimulus[:, :, :, :] = 0

i = 0
j = 0
k = 0
while (i != f):
    while (j != h):
        while (k != w):
            if (env[j, k, i] > 128):
                stimulus[i, j, k, :] = 128 + (env[j, k, i] - 2)/2
            else:
                stimulus[i, j, k, 2] = 255
                stimulus[i, j, k, :2] = env[j, k, i]
            k += 1
        k = 0
        j += 1
    j = 0
    i += 1

lb.saveMovie(stimulus, 'stimulus_movie', vext='.gif')
lb.show_stimulus(stimulus, 'stimulus')
