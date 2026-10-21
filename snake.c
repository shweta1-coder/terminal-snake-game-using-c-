#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 15

typedef struct {
    int x;
    int y;
} Point;

Point snake[100];
int snake_length;
Point food;
char direction;
int score;
int game_over;

void setup() {
    game_over = 0;
    score = 0;
    direction = 'd';
    
    snake_length = 3;
    snake[0].x = WIDTH / 2;
    snake[0].y = HEIGHT / 2;
    
    snake[1].x = (WIDTH / 2) - 1;
    snake[1].y = HEIGHT / 2;
    
    snake[2].x = (WIDTH / 2) - 2;
    snake[2].y = HEIGHT / 2;

    srand(time(0));
    food.x = rand() % (WIDTH - 2) + 1;
    food.y = rand() % (HEIGHT - 2) + 1;
}

void draw() {
    printf("\033[H\033[J"); // Clear screen code for clean rendering
    printf("=========================================\n");
    printf("         RETRO TERMINAL SNAKE IN C       \n");
    printf("=========================================\n");
    printf(" Controls: W = Up | A = Left | S = Down | D = Right | X = Quit\n");
    printf(" Current Score: %d\n\n", score);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (y == 0 || y == HEIGHT - 1 || x == 0 || x == WIDTH - 1) {
                printf("#");
            } else {
                char pixel = ' ';
                if (x == food.x && y == food.y) {
                    pixel = '*';
                }
                for (int i = 0; i < snake_length; i++) {
                    if (x == snake[i].x && y == snake[i].y) {
                        pixel = (i == 0) ? 'O' : 'o';
                        break;
                    }
                }
                printf("%c", pixel);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void logic() {
    Point prev = snake[0];
    Point prev2;
    
    for (int i = 1; i < snake_length; i++) {
        prev2 = snake[i];
        snake[i] = prev;
        prev = prev2;
    }

    if (direction == 'u') snake[0].y--;
    if (direction == 'd') snake[0].y++;
    if (direction == 'l') snake[0].x--;
    if (direction == 'r') snake[0].x++;

    if (snake[0].x == 0 || snake[0].x == WIDTH - 1 || snake[0].y == 0 || snake[0].y == HEIGHT - 1) {
        game_over = 1;
    }

    for (int i = 1; i < snake_length; i++) {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
            game_over = 1;
        }
    }

    if (snake[0].x == food.x && snake[0].y == food.y) {
        score += 10;
        snake_length++;
        food.x = rand() % (WIDTH - 2) + 1;
        food.y = rand() % (HEIGHT - 2) + 1;
    }
}

int main() {
    setup();
    char ch;
    
    while (!game_over) {
        draw();
        printf("Enter move (W/A/S/D) & press Enter: ");
        scanf(" %c", &ch);
        
        if (ch == 'w' || ch == 'W') direction = 'u';
        if (ch == 's' || ch == 'S') direction = 'd';
        if (ch == 'a' || ch == 'A') direction = 'l';
        if (ch == 'd' || ch == 'D') direction = 'r';
        if (ch == 'x' || ch == 'X') break;
        
        logic();
    }

    printf("\n=========================================\n");
    printf("          GAME OVER! Final Score: %d     \n", score);
    printf("=========================================\n");

    return 0;
}