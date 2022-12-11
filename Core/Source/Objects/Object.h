#pragma once
#include <vector>
#include <bgfx/bgfx.h>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

struct PositionNormalUvVertex
{
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 uv;

    static bgfx::VertexLayout getVertexLayout()
    {
        bgfx::VertexLayout vertex_layout;
        vertex_layout.begin()
            .add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
            .add(bgfx::Attrib::Normal, 3, bgfx::AttribType::Float)
            .add(bgfx::Attrib::TexCoord0, 2, bgfx::AttribType::Float)
            .end();
        return vertex_layout;
    }
};

class Object
{
public:
    virtual ~Object() {
        bgfx::destroy(m_vertexBufferHandle);
        bgfx::destroy(m_indexBufferHandle);
    }

    virtual void SubmitObject(bgfx::ProgramHandle program, bool preserve_state = false) const
    {
        assert(m_isInitialized);

        bgfx::setVertexBuffer(0, m_vertexBufferHandle);
        bgfx::setIndexBuffer(m_indexBufferHandle);

        bgfx::submit(0, program, bgfx::ViewMode::Default, preserve_state);
    }
protected:
    std::vector<PositionNormalUvVertex> m_vertices;
    std::vector<uint16_t> m_triangleList;

    bool m_isInitialized = false;

    bgfx::VertexBufferHandle m_vertexBufferHandle;
    bgfx::IndexBufferHandle m_indexBufferHandle;

    virtual void Initialize() {
        assert(!m_vertices.empty());
        assert(!m_triangleList.empty());

        const bgfx::VertexLayout vertexLayout = PositionNormalUvVertex::getVertexLayout();
        m_vertexBufferHandle = bgfx::createVertexBuffer(
            bgfx::makeRef(m_vertices.data(), sizeof(PositionNormalUvVertex) * m_vertices.size()), vertexLayout);
        m_indexBufferHandle = bgfx::createIndexBuffer(
            bgfx::makeRef(m_triangleList.data(), sizeof(uint16_t) * m_triangleList.size()));

        m_isInitialized = true;
    }
};
