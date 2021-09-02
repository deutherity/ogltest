
class OGLapp
{
private:
    int m_width;
    int m_height;
    unsigned int VAOid;
public:
    OGLapp() = default;
    OGLapp(const OGLapp& other) = delete;
    OGLapp& operator= (const OGLapp& other) = delete;

    // initializes openGL in SDLapp
    void init(const int width, const int height);

    // renders frames in cycle()
    void frame();

    // destroys openGL context
    void destroy();

    ~OGLapp() = default;
};




