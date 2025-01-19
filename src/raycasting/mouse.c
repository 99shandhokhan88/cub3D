#include "cub3D.h"

int mouse_move(int x, int y, t_game *game)
{
    static int prev_x;
    double rot_speed;
    double angle;

    prev_x = SCREEN_WIDTH / 2;
    rot_speed = 0.00005;
    angle = (x - prev_x) * rot_speed;

    rotate_player(game, angle);

    prev_x = x;

    (void)y;

    return (0);
}

int handle_mouse_press(int button, int x, int y, t_game *game)
{
    if (button == 1)  // Left mouse button (1 is the code for left mouse button in mlx)
    {
        game->render.keys.mouse_pressed = true;
    }

        (void)y;
                    (void)x;


    return (0);
}

int handle_mouse_release(int button, int x, int y, t_game *game)
{
    if (button == 1)  // Left mouse button
    {
        game->render.keys.mouse_pressed = false;
    }
        (void)y;
            (void)x;

    return (0);
}

void check_cursor_rotation(t_game *game, int mouse_x)
{
    int screen_center = SCREEN_WIDTH / 2;

    if (game->render.keys.left)  // Rotate when left arrow key is pressed
    {
        rotate_player(game, 0.02);  // Rotate left
    }
    else if (game->render.keys.right)  // Rotate when right arrow key is pressed
    {
        rotate_player(game, -0.02);  // Rotate right
    }
    else if (game->render.keys.mouse_pressed)  // Rotate based on mouse position when clicked
    {
        if (mouse_x < screen_center)
        {
            rotate_player(game, 0.02);  // Rotate left
        }
        else if (mouse_x > screen_center)
        {
            rotate_player(game, -0.02);  // Rotate right
        }

        // Reset the cursor to the center of the screen
        //mlx_mouse_move(game->render.mlx, game->render.window, screen_center, SCREEN_HEIGHT / 2);
    }
}

/*You will be able to create better games later do not waste too much
time!*/