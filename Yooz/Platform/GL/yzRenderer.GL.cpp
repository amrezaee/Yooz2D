#include <Graphics/yzRenderer.hpp>

#include <Core/yzAssert.hpp>

#include <yzDeps.hpp>

namespace yz
{
Renderer::Renderer(GraphicsDevice& gd): m_gd(gd)
{
}

void Renderer::Init()
{
	m_gd.SetClearColor(Color::WHITE_SMOKE);

	OnResize(m_gd.GetParams().GetBufferSize());

	m_batcher.Init(10000, m_gd.GetFeatures().FragmentShaderTextureUnits());

	// todo fix this (no absolute path)
	m_shader.LoadAndCompileSourceFiles(
	        "D:\\Amir\\Sources\\Projects\\Yooz2D\\Yooz\\Shader\\renderer_vs.glsl",
	        "D:\\Amir\\Sources\\Projects\\Yooz2D\\Yooz\\Shader\\renderer_fs.glsl");
}

void Renderer::Destroy()
{
	m_batcher.Destroy();
	m_begin = false;
}

void Renderer::Begin()
{
	YZ_ASSERT(!m_begin, "Renderer wrong function order.");

	m_gd.ClearBuffers();

	m_stats.quads      = 0;
	m_stats.draw_calls = 0;

	m_begin = true;
}

void Renderer::Begin(const Camera& camera)
{
	Begin();
	m_camera = camera;
}

void Renderer::End()
{
	YZ_ASSERT(m_begin, "Renderer wrong function order.");

	m_shader.Bind();

	m_batcher.Done();

	m_shader.SetTransform("uViewProj", m_camera.GetViewProjection());

	glDrawElements(GL_TRIANGLES, m_batcher.GetIndicesCount(), GL_UNSIGNED_INT, 0);

	++m_stats.draw_calls;
	++m_stats.total_draw_calls;

	m_batcher.Reset();

	m_begin = false;
}

const RenderStats& Renderer::GetStats() const
{
	return m_stats;
}

void Renderer::OnResize(Vec2u size)
{
	m_camera.SetProjection(0.0f, static_cast<float>(size.x), 0.0f,
	                       static_cast<float>(size.y));
}

void Renderer::DrawQuad(const Texture& texture, const Color color, const Vec2 pos,
                        const Vec2 scale, const float angle, const Vec2 origin)
{
	BatchData b {texture,
	             {{0.0f, 0.0f}, {1.0f, 0.0f}, {1.0f, 1.0f}, {0.0f, 1.0f}},
	             {color, color, color, color},
	             pos,
	             scale,
	             origin,
	             angle};

	if(!m_batcher.Add(b))
	{
		End();
		m_begin = true;
		m_batcher.Add(b);
	}

	++m_stats.quads;
	++m_stats.total_quads;
}

void Renderer::DrawQuad(const Texture& texture, const Color color, const Vec2 pos,
                        const Vec2 scale, const float angle)
{
	DrawQuad(texture, color, pos, scale, angle, {0.0f});
}

void Renderer::DrawQuad(const Texture& texture, const Vec2 pos)
{
	DrawQuad(texture, Color::TRANS_WHITE, pos, {1.0f, 1.0f}, 0.0f, {0.0f});
}

void Renderer::DrawQuad(const Color color, const Vec2 pos, const Vec2 scale,
                        const float angle, const Vec2 origin)
{
	DrawQuad(m_batcher.GetDefaultTexture(), color, pos, scale, angle, origin);
}

void Renderer::DrawQuad(const Color color, const Vec2 pos, const Vec2 scale,
                        const float angle)
{
	DrawQuad(color, pos, scale, angle, {0.0f});
}
void Renderer::DrawQuad(const Color color, const Vec2 pos)
{
	DrawQuad(color, pos, {1.0f}, {0.0f}, {0.0f});
}
}  // namespace yz
