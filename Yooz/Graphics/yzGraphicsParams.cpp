#include <Graphics/yzGraphicsParams.hpp>


namespace yz
{
const std::uint32_t GraphicsParams::m_default_fps {60};
const std::uint32_t GraphicsParams::m_default_buffer_width {960};
const std::uint32_t GraphicsParams::m_default_buffer_height {540};
const float         GraphicsParams::m_default_aspect_ratio {1.77777f};

GraphicsParams::GraphicsParams()
{
	Reset();
}

void GraphicsParams::Reset()
{
	m_window_handle = nullptr;
	m_fs_mode       = FullscreenMode::Windowed;
	m_msaa_level    = MSAALevel::None;
	m_vsync         = false;
	m_buffer_width  = m_default_buffer_width;
	m_buffer_height = m_default_buffer_height;
}

std::uint32_t GraphicsParams::GetDefaultFPS() const
{
	return m_default_fps;
}

std::uint32_t GraphicsParams::GetDefaultBufferWidth() const
{
	return m_default_buffer_width;
}

std::uint32_t GraphicsParams::GetDefaultBufferHeight() const
{
	return m_default_buffer_height;
}

float GraphicsParams::GetDefaultAspectRatio() const
{
	return m_default_aspect_ratio;
}

std::uint32_t GraphicsParams::GetBufferWidth() const
{
	return m_buffer_width;
}

std::uint32_t GraphicsParams::GetBufferHeight() const
{
	return m_buffer_height;
}

Vec2u GraphicsParams::GetBufferSize() const
{
	return {m_buffer_width, m_buffer_height};
}

float GraphicsParams::GetAspectRatio() const
{
	return static_cast<float>(m_buffer_width) / m_buffer_height;
}

void GraphicsParams::SetBufferWidth(std::uint32_t width)
{
	m_buffer_width = width;
}

void GraphicsParams::SetBufferHeight(std::uint32_t height)
{
	m_buffer_height = height;
}

void GraphicsParams::SetBufferSize(Vec2u size)
{
	m_buffer_width  = size.x;
	m_buffer_height = size.y;
}

Handle GraphicsParams::GetWindowHandle() const
{
	return m_window_handle;
}

void GraphicsParams::SetWindowHandle(Handle handle)
{
	m_window_handle = handle;
}

FullscreenMode GraphicsParams::GetFullscreenMode() const
{
	return m_fs_mode;
}

void GraphicsParams::SetFullscreenMode(FullscreenMode fsmode)
{
	m_fs_mode = fsmode;
}

MSAALevel GraphicsParams::GetMSAALevel() const
{
	return m_msaa_level;
}

void GraphicsParams::SetMSAALevel(MSAALevel level)
{
	m_msaa_level = level;
}

bool GraphicsParams::GetVsync() const
{
	return m_vsync;
}

void GraphicsParams::SetVsync(bool enable)
{
	m_vsync = enable;
}
}  // namespace yz
