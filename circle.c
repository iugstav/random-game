#include <math.h>
#include <raylib.h>

typedef struct Circle {
  Vector2 center;
  float radius;
  float speed_x;
  float speed_y;
} Circle;

typedef struct Bar {
  Rectangle rec;
  float speed;
} Bar;

int main() {

  InitWindow(1080, 800, "qualquer coisa");
  SetTargetFPS(60);

  Circle ball = {
      .center = (Vector2){GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f},
      .radius = 20.0f,
      .speed_x = 4.0f,
      .speed_y = 4.0f,
  };
  Circle ball_copy;

  Rectangle rec_bar = {GetScreenWidth() / 2.0f, GetScreenHeight() * 0.8f, 150, 20};
  Bar bar = {rec_bar, 3.5f};

  Vector2 lside = {0, GetScreenHeight() * 0.8f};

  while (!WindowShouldClose()) {
    ball.center.x += ball.speed_x;
    ball.center.y += ball.speed_y;

    ball_copy = ball;
    ball_copy.center.x += ball.speed_x / 2.0f;
    ball_copy.center.y += ball.speed_y / 2.0f;

    if (CheckCollisionCircleRec(ball_copy.center, ball_copy.radius, bar.rec)) {
      ball.speed_y *= -1;
    }

    if (((ball.center.x + ball.radius) >= GetScreenWidth()) ||
        ((ball.center.x - ball.radius) <= 0))
      ball.speed_x *= -1;

    if (((ball.center.y + ball.radius) >= GetScreenHeight()) ||
        ((ball.center.y - ball.radius) <= 0))
      ball.speed_y *= -1;

    if (IsKeyDown(KEY_LEFT)) {
      bar.rec.x -= bar.speed;
    } else if (IsKeyDown(KEY_RIGHT)) {
      bar.rec.x += bar.speed;
    }

    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawRectangleRec(bar.rec, BLUE);

    if ((bar.rec.x + bar.rec.width) < 0) {
      bar.rec.x = GetScreenWidth();
    }
    if (bar.rec.x > GetScreenWidth()) {
      bar.rec.x = bar.rec.width * -1;
    }

    DrawCircleV(ball.center, 20, RED);

    EndDrawing();
  }

  return 0;
}
