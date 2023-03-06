from manim import *

class ThreeDCameraRotation(ThreeDScene):
    def construct(self):
        self.camera.background_color = WHITE
        self.set_camera_orientation(phi=0 * DEGREES, theta=0* DEGREES)
        axes = ThreeDAxes()
        circle = Circle(radius=1, color=RED)
        path = Arc(radius=1, angle=45*DEGREES,stroke_width=0.1)
        self.add(circle, axes)


        sphere = Sphere(radius=0.1,color=RED).shift(RIGHT)
        
        Everything = VGroup()
        Everything.add(axes)
        Everything.add(circle)
        Everything.add(sphere)
        Everything.add(path)
        
        self.play(Rotate(Everything,90*DEGREES,np.array([0,1,0])),MoveAlongPath(sphere, path), run_time=3, rate_func=linear)

        self.wait()