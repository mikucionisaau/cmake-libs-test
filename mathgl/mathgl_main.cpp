#include <mgl2/glut.h>

int sample(HMGL gr, void*)
{
    mgl_rotate(gr, 60, 40, 0);
    mgl_box(gr);
}

int main(int argc, char** argv)
{
    mglGLUT gr(sample, "MathGL examples");
    return 0;
}
