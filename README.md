# Pong

Game Pong đơn giản viết bằng C++ và [raylib](https://www.raylib.com/) 5.0.

**Chơi ngay:** https://leanhson82.github.io/PongGame/

## Cách chơi

- `W` / `S`: di chuyển vợt (bên phải) lên / xuống
- Đánh bóng qua phía CPU để ghi điểm

## Build

Desktop:

```sh
cmake -S . -B build
cmake --build build
./build/mygame
```

Web (cần [Emscripten](https://emscripten.org/)):

```sh
emcmake cmake -S . -B build-web -DCMAKE_BUILD_TYPE=Release
cmake --build build-web
# mở build-web/index.html qua một web server, ví dụ:
python -m http.server -d build-web
```

Mỗi lần push lên `main`, GitHub Actions tự build bản web và deploy lên GitHub Pages.

## Tác giả

[LEANHSON82](https://github.com/LEANHSON82)
