// main.cpp
#include "lorenzattractor.hxx"
#include <GLFW/glfw3.h>
#include <vector>
#include <cmath>

// --- rotate with mouse ---
float rotX = 0.0f, rotY = 0.0f;
double lastX, lastY;
bool mousePressed = false;

void mouse_button_callback(GLFWwindow* w, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT)
        mousePressed = (action == GLFW_PRESS);
}

void cursor_callback(GLFWwindow* w, double xpos, double ypos) {
    if (mousePressed) {
        rotY += (xpos - lastX) * 0.5f;
        rotX += (ypos - lastY) * 0.5f;
    }
    lastX = xpos; lastY = ypos;
}

int main() {
    // --- init GLFW ---
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 800, "Lorenz Attractor", NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetCursorPosCallback(window, cursor_callback);

    // --- init attractor ---
    LorenzAttractor lorenz(0.1, 0.0, 0.0, 10.0, 8.0/3.0, 28.0, 1e-3);

    std::vector<float> xs, ys, zs;
    const int MAX_POINTS = 50000;

    // --- main loop ---
    while (!glfwWindowShouldClose(window)) {
        // simulate a few steps per frame
        for (int i = 0; i < 50; i++) {
            lorenz.step();
            xs.push_back(lorenz.x);
            ys.push_back(lorenz.y);
            zs.push_back(lorenz.z);
        }
        // cap trail length
        if (xs.size() > MAX_POINTS) {
            xs.erase(xs.begin(), xs.begin() + 50);
            ys.erase(ys.begin(), ys.begin() + 50);
            zs.erase(zs.begin(), zs.begin() + 50);
        }

        // --- draw ---
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glFrustum(-1, 1, -1, 1, 1.5, 200.0);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0, 0, -60);         // zoom out
        glRotatef(rotX, 1, 0, 0);        // mouse rotation
        glRotatef(rotY, 0, 1, 0);
        glScalef(0.5f, 0.5f, 0.5f);      // scale down

        // color gradient along the trail
        glBegin(GL_LINE_STRIP);
        int n = xs.size();
        for (int i = 0; i < n; i++) {
            float t = (float)i / n;
            glColor3f(t, 0.3f, 1.0f - t); // blue → red gradient
            glVertex3f(xs[i], ys[i], zs[i]);
        }
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
};