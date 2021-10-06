import pygame
import math
pygame.init()
pixel_size = 2
black = (255, 255, 255)
white = (0, 0, 0)
screen_width = 800
screen_height = 600
screen_display = pygame.display.set_mode((screen_width, screen_height))
screen_display.fill(black)
pygame.display.set_caption("Bresenham Circle")

def bresenham_circle(Cx, Cy, rad):
    screen_close = False
    while not screen_close:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                screen_close = True

        x = 0
        y = rad
        d = 3 - 2*rad

        while x <= rad / math.sqrt(2):

            # O* - 45*
            pygame.draw.rect(screen_display, white, [Cx + y, Cy - x, pixel_size, pixel_size])
            # 45* - 90*
            pygame.draw.rect(screen_display, white, [Cx + x, Cy - y, pixel_size, pixel_size])
            # 90* - 135*
            pygame.draw.rect(screen_display, white, [Cx - x, Cy - y, pixel_size, pixel_size])
            # 135* - 180*
            pygame.draw.rect(screen_display, white, [Cx - y, Cy - x, pixel_size, pixel_size])
            # 180* - 225*
            pygame.draw.rect(screen_display, white, [Cx - y, Cy + x, pixel_size, pixel_size])
            # 225* - 270*
            pygame.draw.rect(screen_display, white, [Cx - x, Cy + y, pixel_size, pixel_size])
            # 270* - 315*
            pygame.draw.rect(screen_display, white, [Cx + x, Cy + y, pixel_size, pixel_size])
            # 315* - 360*
            pygame.draw.rect(screen_display, white, [Cx + y, Cy + x, pixel_size, pixel_size])

            if (d < 0):
                d = d + 4 * x + 6

            else:
                d = d + 4 * x - 4 * y + 10
                y -= 1

            x += 1

        pygame.display.update()

#driver code
x = 350
y = 250
r = 150
bresenham_circle(x, y, r)
pygame.quit()
