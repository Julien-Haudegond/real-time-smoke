#pragma once

#include "Scene/Components.hpp"
#include <entt.hpp>

#include <QVector>

#include "Renderer/SdfRenderer.hpp"
#include "Camera/Camera.hpp"

	class Entity;
	class Mesh;
	class Triangle2D;

	class Scene
	{
	public:
		Scene();
		virtual ~Scene() = default;

		Entity CreateEntity(const std::string& name = std::string(), const TransformComp& transform = TransformComp());
		Triangle2D CreateTriangle2D(const std::string& name = std::string(), const TransformComp& transform = TransformComp(), glm::vec4 color = glm::vec4({ 8.0f, 2.0f, 3.0f, 1.0f }) );
		
		void onUpdate();
		void onMousePress();
		void onMouseRelease();
		void onWheelScroll(float delta);

	private:
		entt::registry m_Registry;
		SdfRenderer _sdfRenderer;
		Camera _camera;

		friend class Entity;
		friend class Mesh;
		friend class Triangle2D;
	};
