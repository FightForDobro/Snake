//#include <Magnum/GL/Buffer.h>
//#include <Magnum/GL/DefaultFramebuffer.h>
//#include <Magnum/GL/Mesh.h>
//#include <Magnum/GL/Renderer.h>
//#include <Magnum/Math/Color.h>
//#include <Magnum/Math/Matrix4.h>
//#include <Magnum/MeshTools/Interleave.h>
//#include <Magnum/MeshTools/CompressIndices.h>
//#include <Magnum/Platform/Sdl2Application.h>
//#include <Magnum/Primitives/Cube.h>
//#include <Magnum/Shaders/Phong.h>
//#include <Magnum/Trade/MeshData.h>
//#include <Magnum/Shaders/VertexColor.h>
//#include <Magnum/MeshTools/Compile.h>

#include <SDL.h>
#include <iostream>
#include <random>
#include "src/snake.h"

//namespace Magnum { namespace Examples {
//
//        using namespace Magnum::Math::Literals;
//
//        class PrimitivesExample: public Platform::Application {
//        public:
//            explicit PrimitivesExample(const Arguments& arguments);
//
//        private:
//            void drawEvent() override;
////            void mousePressEvent(MouseEvent& event) override;
////            void mouseReleaseEvent(MouseEvent& event) override;
////            void mouseMoveEvent(MouseMoveEvent& event) override;
//            void keyPressEvent(KeyEvent& event) override;
//
//            float _xpos = 0.1f;
//            float _ypos = 0.1f;
//            float _zpos = 0.1f;
//
//            GL::Mesh _mesh;
//            Shaders::Phong _shader;
//
//            Matrix4 _transformation, _projection;
//            Color3 _color;
//        };
//
//        PrimitivesExample::PrimitivesExample(const Arguments& arguments):
//                Platform::Application{arguments, Configuration{}
//                        .setTitle("Magnum Primitives Example")}
//        {
//            GL::Renderer::enable(GL::Renderer::Feature::DepthTest);
//            GL::Renderer::enable(GL::Renderer::Feature::FaceCulling);
//
//            Trade::MeshData cube = Primitives::cubeSolid();
//
//            GL::Buffer vertices;
//            vertices.setData(MeshTools::interleave(cube.positions3DAsArray(),
//                                                   cube.normalsAsArray()));
//
//            std::pair<Containers::Array<char>, MeshIndexType> compressed =
//                    MeshTools::compressIndices(cube.indicesAsArray());
//            GL::Buffer indices;
//            indices.setData(compressed.first);
//
//            _mesh.setPrimitive(cube.primitive())
//                    .setCount(cube.indexCount())
//                    .addVertexBuffer(std::move(vertices), 0, Shaders::Phong::Position{},
//                                     Shaders::Phong::Normal{})
//                    .setIndexBuffer(std::move(indices), 0, compressed.second);
//
//            _transformation = Matrix4::scaling({1, 1, 0.1f});
////                    Matrix4::rotationX(30.0_degf)*Matrix4::rotationY(40.0_degf);
//            _projection =
//                    Matrix4::perspectiveProjection(
//                            95.0_degf, Vector2{windowSize()}.aspectRatio(), 0.01f, 100.0f)*
//                    Matrix4::translation(Vector3::zAxis(-10.0f));
//            _color = Color3::fromHsv({35.0_degf, 1.0f, 1.0f});
//        }
//
//        void PrimitivesExample::drawEvent() {
//            GL::defaultFramebuffer.clear(
//                    GL::FramebufferClear::Color|GL::FramebufferClear::Depth);
//
////            _shader.setLightPositions({{7.0f, 5.0f, 2.5f, 0.0f}})
//////                    .setDiffuseColor(_color)
//////                    .setAmbientColor(Color3::fromHsv({_color.hue(), 1.0f, 0.3f}))
////                    .setTransformationMatrix(_transformation)
////                    .setNormalMatrix(_transformation.normalMatrix())
////                    .setProjectionMatrix(_projection)
////                    .draw(_mesh);
//
//            _shader.setTransformationMatrix(_transformation)
//            .setProjectionMatrix(_projection)
//            .draw(_mesh);
//
//            swapBuffers();
//        }
//
////        void PrimitivesExample::mousePressEvent(MouseEvent& event) {
////            if(event.button() != MouseEvent::Button::Left) return;
////
////            event.setAccepted();
////        }
////
////        void PrimitivesExample::mouseReleaseEvent(MouseEvent& event) {
////            _color = Color3::fromHsv({_color.hue() + 50.0_degf, 1.0f, 1.0f});
////
////            event.setAccepted();
////            redraw();
////        }
//
////        void PrimitivesExample::mouseMoveEvent(MouseMoveEvent& event) {
////            if(!(event.buttons() & MouseMoveEvent::Button::Left)) return;
////
////            Vector2 delta = 3.0f * Vector2{event.relativePosition()} / Vector2{windowSize()};
////
////            _transformation =
////                    Matrix4::rotationX(Rad{delta.y()})*
////                    _transformation*
////                    Matrix4::rotationY(Rad{delta.x()});
////
////            event.setAccepted();
////            redraw();
////        }
//
//        void PrimitivesExample::keyPressEvent(Platform::Sdl2Application::KeyEvent &event)
//        {
//            if(event.key() == KeyEvent::Key::Down) {
//                _transformation = Magnum::Matrix4::translation({_xpos += 0, _ypos -= 0.3f, _zpos = 0}) + Matrix4::scaling({1, 1, 0.1f});
//            } else if(event.key() == KeyEvent::Key::Up) {
//                _transformation = Magnum::Matrix4::translation({_xpos += 0, _ypos += 0.3f, _zpos = 0}) + Matrix4::scaling({1, 1, 0.1f});
//            } else if(event.key() == KeyEvent::Key::Left) {
//                _transformation = Magnum::Matrix4::translation({_xpos -= 0.3f, _ypos += 0, _zpos = 0}) + Matrix4::scaling({1, 1, 0.1f});
//            } else if(event.key() == KeyEvent::Key::Right) {
//                _transformation = Magnum::Matrix4::translation({_xpos += 0.3f, _ypos += 0, _zpos = 0}) + Matrix4::scaling({1, 1, 0.1f});
//            }
//
////            _transformation = Magnum::Matrix4::scaling({2, 2, 2});
//            event.isAccepted();
//            redraw();
//        }
//
//    }
//}

//namespace Magnum::Examples {
//    using namespace Magnum::Math::Literals;
//
//    typedef SceneGraph::Object<SceneGraph::MatrixTransformation2D> Object2D;
//    typedef SceneGraph::Scene<SceneGraph::MatrixTransformation2D> Scene2D;
//
//    class BodyPart
//    {
//    public:
//        explicit BodyPart(float xpos, float ypos, Vector2i winsize)
//        {
//            _xpos = xpos;
//            _ypos = ypos;
//
//            Trade::MeshData cube = Primitives::squareSolid();
//            _mesh = MeshTools::compile(cube);
//
//            _transformation = Magnum::Matrix3::translation({_xpos, _ypos}) * Matrix3::scaling({4, 4});
//            _projection = Matrix3::projection(Vector2{winsize});
//        }
//
//        void draw()
//        {
//            _shader.setTransformationProjectionMatrix(_projection * _transformation)
//                    .draw(_mesh);
//        }
//
//    private:
//
//        GL::Mesh _mesh;
//        float _xpos;
//        float _ypos;
//
//        Shaders::Flat2D _shader{Shaders::Flat2D::Flag::VertexColor};
//        Matrix3 _transformation, _projection;
//    };
//
//    class MapS
//    {
//    public:
//        explicit MapS(Vector2i winsize)
//        {
//            Trade::MeshData cube = Primitives::squareSolid();
//            _mesh = MeshTools::compile(cube);
//            _xpos = 250.0f;
//            _ypos = 12.0f;
//            _transformation = Magnum::Matrix3::translation({_xpos, _ypos}) * Matrix3::scaling({4, 4});
//            _projection = Matrix3::projection(Vector2{winsize});
//        }
//
//        void draw()
//        {
//            for (int i = 1; i <= 16; i++)
//            {
//                _transformation = (Magnum::Matrix3::translation({_xpos, _ypos += 12}) * Matrix3::scaling({4, 4}));
//                _shader.setTransformationProjectionMatrix(_projection * _transformation)
//                .draw(_mesh);
//            }
//
//
//            for (int i = 0; i <= 16 * 2; i++)
//            {
//                _transformation = (Magnum::Matrix3::translation({(_xpos -= 12), _ypos}) * Matrix3::scaling({4, 4}));
//                _shader.setTransformationProjectionMatrix(_projection * _transformation)
//                        .draw(_mesh);
//            }
//
//            for (int i = 1; i <= 16; i++)
//            {
//                _transformation = (Magnum::Matrix3::translation({_xpos, _ypos -= 12}) * Matrix3::scaling({4, 4}));
//                _shader.setTransformationProjectionMatrix(_projection * _transformation)
//                        .draw(_mesh);
//            }
//
//            for (int i = 1; i <= (16 * 2) + 1; i++)
//            {
//                _transformation = (Magnum::Matrix3::translation({_xpos += 12, _ypos}) * Matrix3::scaling({4, 4}));
//                _shader.setTransformationProjectionMatrix(_projection * _transformation)
//                        .draw(_mesh);
//            }
//
//
//        }
//
//    private:
//        float _xpos;
//        float _ypos;
//        GL::Mesh _mesh;
//        Shaders::Flat2D _shader{Shaders::Flat2D::Flag::VertexColor};
//        Matrix3 _transformation, _projection;
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
//        void keyPressEvent(KeyEvent &event) override;
//        void idle();
//
//        float _xpos = 35.0f;
//        float _ypos = 35.0f;
//
//        KeyEvent::Key direction;
////        float _lenght = 4.0f;
//
////        Scene2D _scene;
////        Object2D* _cameraObject;
////        SceneGraph::Camera3D* _camera;
////        SceneGraph::DrawableGroup2D _drawables;
//
//
//        GL::Mesh _mesh;
//        std::deque<BodyPart *> _tail;
//        Shaders::Flat2D _shader{Shaders::Flat2D::Flag::VertexColor};
//
//        Matrix3 _transformation, _projection;
//        Timeline _timeline;
//
//    };
//
//    Snake::Snake(const Arguments& arguments):Platform::Application{arguments, Configuration{}
//            .setTitle("Snake Game")}
//    {
////        GL::Renderer::enable(GL::Renderer::Feature::DepthTest);
////        GL::Renderer::enable(GL::Renderer::Feature::FaceCulling);
//
//        Trade::MeshData cube = Primitives::squareSolid();
//
////        GL::Buffer vertexBuffer;
////        vertexBuffer.setData(MeshTools::interleave(cube.positions3DAsArray(),
////                                                   cube.normalsAsArray()));
//
////        GL::Buffer vertices;
////        vertices.setData(MeshTools::interleave(cube.positions3DAsArray(),
////                                               cube.normalsAsArray()));
////
////        std::pair<Containers::Array<char>, MeshIndexType> compressed =
////                MeshTools::compressIndices(cube.indicesAsArray());
////        GL::Buffer indices;
////        indices.setData(compressed.first);
//
//        _mesh = MeshTools::compile(cube);
//
////        _mesh.setPrimitive(cube.primitive())
////                .setCount(cube.indexCount())
////                .addVertexBuffer(std::move(vertices), 0, Shaders::Phong::Position{},
////                                 Shaders::Phong::Normal{})
////                .setIndexBuffer(std::move(indices), 0, compressed.second);
//
//        _transformation = Magnum::Matrix3::translation({_xpos, _ypos}) * Matrix3::scaling({4, 4});
////                    Matrix4::rotationX(30.0_degf)*Matrix4::rotationY(40.0_degf);
//
////        _projection = Matrix3::projection({10.0f, 10.0f}) * Matrix3::translation({10, 10});
//        _projection = Matrix3::projection(Vector2{windowSize()});
////        _tail.push_back(&_mesh);
//        _tail.push_back(new BodyPart(_xpos, _ypos, windowSize()));
////        _projection =
////                Matrix4::perspectiveProjection(
////                        95.0_degf, Vector2{windowSize()}.aspectRatio(), 0.01f, 100.0f)*
////                Matrix4::translation(Vector3::zAxis(-10.0f));
////        _color = Color3::fromHsv({35.0_degf, 1.0f, 1.0f});
//
////        setSwapInterval(1);
////        setMinimalLoopPeriod(16);
////        _timeline.start();
//        redraw();
//    }
//
//    void Snake::drawEvent() {
//        GL::defaultFramebuffer.clear(GL::FramebufferClear::Color);
//
////            _shader.setLightPositions({{7.0f, 5.0f, 2.5f, 0.0f}})
//////                    .setDiffuseColor(_color)
//////                    .setAmbientColor(Color3::fromHsv({_color.hue(), 1.0f, 0.3f}))
////                    .setTransformationMatrix(_transformation)
////                    .setNormalMatrix(_transformation.normalMatrix())
////                    .setProjectionMatrix(_projection)
////                    .draw(_mesh);
//
////        _shader.setTransformationMatrix(_transformation)
////                .setProjectionMatrix(_projection)
////                .draw(_mesh);
//
////        GL::Mesh temp = _mesh;
//
////        _tail.push_back(&_mesh);
//
//        auto maps = new MapS(windowSize());
//        maps->draw();
//
//        Trade::MeshData cube = Primitives::squareSolid();
//
//        _mesh = MeshTools::compile(cube);
//
////        _mesh.setPrimitive(cube.primitive())
////                .setCount(cube.indexCount())
////                .addVertexBuffer(std::move(vertices), 0, Shaders::Phong::Position{},
////                                 Shaders::Phong::Normal{})
////                .setIndexBuffer(std::move(indices), 0, compressed.second);
//
//        _transformation = Magnum::Matrix3::translation({_xpos, _ypos}) * Matrix3::scaling({4, 4});
////                    Matrix4::rotationX(30.0_degf)*Matrix4::rotationY(40.0_degf);
//
////        _projection = Matrix3::projection({10.0f, 10.0f}) * Matrix3::translation({10, 10});
//        _projection = Matrix3::projection(Vector2{windowSize()});
////        _tail.push_back(&_mesh);
//        _tail.push_back(new BodyPart(_xpos, _ypos, windowSize()));
//
//
//        for (auto& b: _tail)
//        {
//            b->draw();
////            _shader.setTransformationProjectionMatrix(_projection * _transformation)
////                    .draw(_mesh);
//        }
//        if (_tail.size() == 6)
//        {
//            _tail.pop_front();
//        }
////        _shader.setTransformationProjectionMatrix(_projection * _transformation)
////        .draw(_mesh);
//
////        _transformation = Magnum::Matrix3::translation({_xpos += 0, _ypos += 10}) * Matrix3::scaling({4, 4});
////        _shader.setTransformationProjectionMatrix(_projection * _transformation)
////        .draw(_mesh);
//        swapBuffers();
//
//        if ((_xpos <= -145 || _xpos >= 245) || (_ypos <= 15 || _ypos >= 205))
//            exit(0);
//        _xpos += 0.1f;
//        redraw();
//    }
//
//    void Snake::keyPressEvent(Platform::Sdl2Application::KeyEvent &event) {
//        direction = event.key();
//
//        if (direction == KeyEvent::Key::Up)
//            _transformation = Magnum::Matrix3::translation({_xpos += 0, _ypos += 10}) * Matrix3::scaling({4, 4});
//
//        else if (direction == KeyEvent::Key::Left)
//            _transformation = Magnum::Matrix3::translation({_xpos -= 10, _ypos += 0}) * Matrix3::scaling({4, 4});
//
//        else if (direction == KeyEvent::Key::Right)
//            _transformation = Magnum::Matrix3::translation({_xpos += 10, _ypos += 0}) * Matrix3::scaling({4, 4});
//
//        else if (direction == KeyEvent::Key::Down)
//            _transformation = Magnum::Matrix3::translation({_xpos -= 0, _ypos -= 10}) * Matrix3::scaling({4, 4});
//
//        if (_tail.size() >= 6)
//        {
//            _tail.pop_front();
//        }
//
//        event.isAccepted();
//        redraw();
//    }
//
//    void Snake::idle()
//    {
//        if (direction == KeyEvent::Key::Up)
//            _transformation = Magnum::Matrix3::translation({_xpos += 0, _ypos += 10}) * Matrix3::scaling({4, 4});
//
//        else if (direction == KeyEvent::Key::Left)
//            _transformation = Magnum::Matrix3::translation({_xpos -= 10, _ypos += 0}) * Matrix3::scaling({4, 4});
//
//        else if (direction == KeyEvent::Key::Right)
//            _transformation = Magnum::Matrix3::translation({_xpos += 10, _ypos += 0}) * Matrix3::scaling({4, 4});
//
//        else if (direction == KeyEvent::Key::Down)
//            _transformation = Magnum::Matrix3::translation({_xpos -= 0, _ypos -= 10}) * Matrix3::scaling({4, 4});
//
//        redraw();
//    }
//
//}


namespace Magnum::Examples
{
    using namespace Magnum::Math::Literals;

    class Fruit
    {
    public:

        explicit Fruit(Vector2i winsize)
        {

            std::random_device rseed;
            std::mt19937 rng(rseed());
            std::uniform_int_distribution<int> x(((winsize.x() / 2) - 10) * -1,(winsize.x() / 2) - 10);
            std::uniform_int_distribution<int> y(((winsize.y() / 2) - 10) * -1,(winsize.y() / 2) - 10);

            _xpos = x(rng);
            _ypos = y(rng);

            Trade::MeshData fruit = Primitives::squareSolid();
            _fruitmesh = MeshTools::compile(fruit);

            _trasnformation = Matrix3::translation({_xpos, _ypos}) * Matrix3::scaling({4, 4});
            _projection = Matrix3::projection(Vector2{winsize});

        }

        float get_x()
        {
            return _xpos;
        }

        float get_y()
        {
            return _ypos;
        }

        std::array<float, 2> draw()
        {
            _shader.setTransformationProjectionMatrix(_projection * _trasnformation)
                    .draw(_fruitmesh);

            std::array fruit_pos = {_xpos, _ypos};
            return fruit_pos;
        }

    private:
        GL::Mesh _fruitmesh;
        float _xpos;
        float _ypos;
        Shaders::Flat2D _shader{Shaders::Flat2D::Flag::VertexColor};
        Matrix3 _trasnformation, _projection;
    };

    class Tail
    {
    public:
        explicit Tail(float xpos, float ypos, Vector2i winsize)
        {
            _xpos = xpos;
            _ypos = ypos;

            Trade::MeshData tail = Primitives::squareSolid();
            _tailmesh = MeshTools::compile(tail);

            _trasnformation = Matrix3::translation({_xpos, _ypos}) * Matrix3::scaling({4, 4});
            _projection = Matrix3::projection(Vector2{winsize});
        }

        void draw()
        {
            _shader.setTransformationProjectionMatrix(_projection * _trasnformation)
                    .draw(_tailmesh);
        }

    private:
        GL::Mesh _tailmesh;
        float _xpos;
        float _ypos;
        Shaders::Flat2D _shader{Shaders::Flat2D::Flag::VertexColor};
        Matrix3 _trasnformation, _projection;
    };

    class Snake : public Platform::Application
    {

    public:
        explicit Snake(const Arguments &arguments);

    private:
        void drawEvent() override;
        void keyPressEvent(KeyEvent &event) override;
        void move();

        GL::Mesh _mesh;
        Shaders::Flat2D _shader;

        float _xpos = 35.0f;
        float _ypos = 35.0f;

        bool _fruit = false;
        Fruit *__fruit = nullptr;

        int _size = 64;
        float _speed = 0.3602672f;
        std::deque<Tail *> _tail;
        KeyEvent::Key _dir;

        Matrix3 _transformation, _projection;

    };

    Snake::Snake(const Arguments& arguments):Platform::Application{arguments, Configuration{}
            .setTitle("Snake Game")}
    {
        Trade::MeshData head = Primitives::squareSolid();
        _mesh = MeshTools::compile(head);

        _transformation = Magnum::Matrix3::translation({_xpos, _ypos}) * Matrix3::scaling({4, 4});
        _projection = Matrix3::projection(Vector2{windowSize()});

        _dir = KeyEvent::Key::W;

        for (int i = 1; i <= 3; ++i)
            _tail.push_front(new Tail(_xpos - (10 * i) , _ypos, windowSize()));

        redraw();
    }

    void Snake::drawEvent()
    {
        GL::defaultFramebuffer.clear(GL::FramebufferClear::Color);
//        _shader.setTransformationProjectionMatrix(_transformation * _projection).draw(_mesh);

        _tail.push_back(new Tail(_xpos, _ypos, windowSize()));

        for (auto& t: _tail)
            t->draw();

        if (_tail.size() > _size)
            _tail.pop_front();

        if (!_fruit)
        {
            __fruit = new Fruit(windowSize());
            _fruit = true;
        }

//        else if ((_xpos >= __fruit->get_x() || _xpos <= __fruit->get_x()) &&
//                 (_ypos >= __fruit->get_y() || _ypos <= __fruit->get_y()))

        else if ((_xpos >= __fruit->get_x() - 8 && _xpos <= __fruit->get_x() + 8) &&
                 (_ypos >= __fruit->get_y() - 8 && _ypos <= __fruit->get_y() + 8))
        {
//            delete __fruit;
            _size *= 1.1;
            _speed *= 1.009491571571f;
            _fruit = false;
        }

        if (__fruit)
            __fruit->draw();

        if (_xpos >= windowSize().x() / 2 || _ypos >= windowSize().y() / 2 ||
            _xpos <= windowSize().x() / 2 * -1 || _ypos <= windowSize().y() / 2 * -1)
            exit(0);

//        std::cout << "xPos:" <<_xpos << std::endl;
//        std::cout << "yPos:" <<_ypos << std::endl;

        swapBuffers();
        move();
    }

    void Snake::keyPressEvent(KeyEvent &event)
    {
        if (event.key() == KeyEvent::Key::W || event.key() == KeyEvent::Key::A
         || event.key() == KeyEvent::Key::S || event.key() == KeyEvent::Key::D)
            _dir = event.key();

        event.isAccepted();
        redraw();
    }

    void Snake::move()
    {
        if (_dir == KeyEvent::Key::W)
            _transformation = Magnum::Matrix3::translation ({_xpos += 0, _ypos += _speed}) * Matrix3::scaling({4, 4});

        else if (_dir  == KeyEvent::Key::A)
            _transformation = Magnum::Matrix3::translation ({_xpos -= _speed, _ypos += 0}) * Matrix3::scaling({4, 4});

        else if (_dir  == KeyEvent::Key::D)
            _transformation = Magnum::Matrix3::translation ({_xpos += _speed, _ypos += 0}) * Matrix3::scaling({4, 4});

        else if (_dir  == KeyEvent::Key::S)
            _transformation = Magnum::Matrix3::translation ({_xpos -= 0, _ypos -= _speed}) * Matrix3::scaling({4, 4});
        redraw();
    }


}

MAGNUM_APPLICATION_MAIN(Magnum::Examples::Snake)
