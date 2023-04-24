import pygame
import math

pygame.init()

pixel_size = 1

# COLOR CODE
black = (0, 0, 0)
white = (255, 255, 255)

# SIZE PARAMETERS
screen_width = 800
screen_height = 600

# SET SCREEN SIZE
screen_display = pygame.display.set_mode((screen_width, screen_height))
screen_display.fill(black)

# TITLE
pygame.display.set_caption("Midpoint Ellipse")

def mp_ellipse(Cx, Cy, Rx, Ry):

    screen_close = False
    while not screen_close:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                screen_close = True

        x = 0
        y = Ry

        # Decision parameter of region 1
        D1 = ((Ry * Ry) - (Rx * Rx * Ry) +
                (0.25 * Rx * Rx))
        Dx = 2 * Ry * Ry * x
        Dy = 2 * Rx * Rx * y

        # Region 1
        while (Dx < Dy):

            pygame.draw.rect(screen_display, white, [Cx + x, Cy + y, pixel_size, pixel_size])
            pygame.draw.rect(screen_display, white, [Cx + x, Cy - y, pixel_size, pixel_size])
            pygame.draw.rect(screen_display, white, [Cx - x, Cy + y, pixel_size, pixel_size])
            pygame.draw.rect(screen_display, white, [Cx - x, Cy - y, pixel_size, pixel_size])

            if (D1 < 0):
                x += 1
                Dx = Dx + (2 * Ry * Ry)
                D1 = D1 + Dx + (Ry * Ry)
            else:
                x += 1
                y -= 1
                Dx = Dx + (2 * Ry * Ry)
                Dy = Dy - (2 * Rx * Rx)
                D1 = D1 + Dx - Dy + (Ry * Ry)

        # Decision parameter of region 2
        D2 = (((Ry * Ry) * ((x + 0.5) * (x + 0.5))) + ((Rx * Rx) * ((y - 1) * (y - 1))) - (Rx * Rx * Ry * Ry))

        # Region 2
        while (y >= 0):

            pygame.draw.rect(screen_display, white, [Cx + x, Cy + y, pixel_size, pixel_size])
            pygame.draw.rect(screen_display, white, [Cx + x, Cy - y, pixel_size, pixel_size])
            pygame.draw.rect(screen_display, white, [Cx - x, Cy + y, pixel_size, pixel_size])
            pygame.draw.rect(screen_display, white, [Cx - x, Cy - y, pixel_size, pixel_size])

            if (D2 > 0):
                y -= 1
                Dy = Dy - (2 * Rx * Rx)
                D2 = D2 + (Rx * Rx) - Dy
            else:
                y -= 1
                x += 1
                Dx = Dx + (2 * Ry * Ry)
                Dy = Dy - (2 * Rx * Rx)
                D2 = D2 + Dx - Dy + (Rx * Rx)

        pygame.display.update()

# Pre-defined Input
x = 400
y = 300
a = 200
b = 150

mp_ellipse(x, y, a, b)
pygame.quit()