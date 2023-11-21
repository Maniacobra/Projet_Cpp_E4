#include <space-shooter/ecs/entity.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

#include <filesystem>

#include <space-shooter/ecs/components/enemy_component.hpp>



namespace space_shooter::ecs {

	class EnemyEntity : public Entity {
	public:
		EnemyEntity(sf::Vector2f pos, int sizeX, int sizeY, EnemyType type,const std::filesystem::path& texture_path);
		EnemyEntity() = delete;

		using Entity::Entity;
	};

} // namespace space_shooter::ecs
