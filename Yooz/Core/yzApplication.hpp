#pragma once

#include <Core/yzAssert.hpp>
#include <Core/yzWindow.hpp>
#include <Graphics/yzGraphicsDevice.hpp>
#include <Graphics/yzGraphicsParams.hpp>
#include <Graphics/yzRenderer.hpp>
#include <Math/yzRectangle.hpp>
#include <Platform/yzPlatform.hpp>

#include <yzDeps.hpp>
#include <yzSTD.hpp>

namespace yz
{
struct AppSpecs
{
	std::string    name;
	fs::path       working_dir;
	GraphicsParams graphics_params;
};

class Application
{
public:
	Application(AppSpecs& specs);


	const AppSpecs& GetSpecs() const;

	Platform& GetPlatform();

	Window& GetWindow();

	GraphicsDevice& GetGraphicsDevice();

	bool IsActive() const;

	bool IsCursorVisible() const;
	void ShowCursor(bool show);

private:
	void Run();
	void Init();
	void Destroy();
	friend int ::main(int argc, char** argv);


private:
	void OnWindowActive();
	void OnWindowDeactive();
	void OnWindowClose();
	void OnWindowResize(Vec2u size);

private:
	bool m_inited {false};
	bool m_running {true};
	bool m_suspended {false};
	bool m_show_cursor {true};

	AppSpecs       m_specs;
	Platform       m_platform;
	Window         m_window;
	GraphicsDevice m_graphics_device;
	Renderer       m_renderer;
};
}  // namespace yz
