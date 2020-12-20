//#include "snake.h"
//
//namespace Magnum::Examples
//{
//    using namespace Magnum::Math::Literals;
//
//    class Tail
//    {
//    public:
//        explicit Tail(float xpos, float ypos, Vector2i winsise)
//        {
//            _xpos = xpos;
//            _ypos = ypos;
//
//            Trade::MeshData tail = Primitives::squareSolid();
//            _tailmesh = MeshTools::compile(tail);
//
//            _trasnformation = Matrix3::translation({_xpos, _ypos}) * Matrix3::scaling({4, 4});
//            _projection = Matrix3::projection(Vector2{winsise});
//        }
//
//        void draw()
//        {
//            _shader.setTransformationProjectionMatrix(_projection * _trasnformation)
//            .draw(_tailmesh);
//        }
//
//    private:
//        GL::Mesh _tailmesh;
//        float _xpos;
//        float _ypos;
//        Shaders::Flat2D _shader{Shaders::Flat2D::Flag::VertexColor};
//        Matrix3 _trasnformation, _projection;
//    };
//
//    class Snake : public Platform::Application
//    {
//
//    public:
//        explicit Snake(const Arguments &arguments);
//
//    private:
//        void drawEvent() override;
//
//        void keyPressEvent(KeyEvent &event) override;
//
//        GL::Mesh _mesh;
//        Shaders::Flat2D _shader;
//
//        float _xpos = 35.0f;
//        float _ypos = 35.0f;
//
//        Platform::Sdl2Application::KeyEvent::Key _dir;
//
//        std::deque<Tail *> _tail;
//
//        Matrix3 _transformation, _projection;
//
//    };
//
//    Snake::Snake(const Arguments& arguments):Platform::Application{arguments, Configuration{}
//                    .setTitle("Snake Game")}
//    {
//        Trade::MeshData head = Primitives::squareSolid();
//        _mesh = MeshTools::compile(head);
//
//        _transformation = Magnum::Matrix3::translation({_xpos, _ypos}) * Matrix3::scaling({4, 4});
//        _projection = Matrix3::projection(Vector2{windowSize()});
//
//        _dir = Platform::Sdl2Application::KeyEvent::Key::W;
//
//        for (int i = 1; i <= 3; ++i)
//            _tail.push_front(new Tail(_xpos - (10 * i) , _ypos, windowSize()));
//
//        redraw();
//    }
//
//    void Snake::drawEvent()
//    {
//        GL::defaultFramebuffer.clear(GL::FramebufferClear::Color);
//
//        _shader.setTransformationProjectionMatrix(_transformation * _projection).draw(_mesh);
//
//        for (auto& t: _tail)
//            t->draw();
//
//        swapBuffers();
//    }
//
//    void Snake::keyPressEvent(Platform::Sdl2Application::KeyEvent &event)
//    {
//        _dir = event.key();
//
//        if (_dir == KeyEvent::Key::W)
//        _transformation = Magnum::Matrix3::translation
//                ({_xpos += 0, _ypos += 10}) * Matrix3::scaling({4, 4});
//
//        else if (_dir == KeyEvent::Key::A)
//            _transformation = Magnum::Matrix3::translation
//                    ({_xpos -= 10, _ypos += 0}) * Matrix3::scaling({4, 4});
//
//        else if (_dir == KeyEvent::Key::D)
//            _transformation = Magnum::Matrix3::translation
//                    ({_xpos += 10, _ypos += 0}) * Matrix3::scaling({4, 4});
//
//        else if (_dir == KeyEvent::Key::S)
//            _transformation = Magnum::Matrix3::translation
//                    ({_xpos -= 0, _ypos -= 10}) * Matrix3::scaling({4, 4});
//
//        event.isAccepted();
//        redraw();
//    }
//
//}
////
//////MAGNUM_APPLICATION_MAIN(Magnum::Examples::PrimitivesExample);