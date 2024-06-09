#include "pch.h"
#include "..\Cast_Library\Systems\Cast_Interface.h"

TEST(BlueprintTest, AcidSplash) {

	ID owner = 1;

	ID cast = createAcidSplash(owner);

  EXPECT_EQ(testComponent(cast, CASTING_COMP), true);
  EXPECT_EQ(testComponent(cast, UPCAST_COMP), false);
  EXPECT_EQ(testComponent(cast, SAVING_COMP), true);
  EXPECT_EQ(testComponent(cast, DAMAGE_COMP), true);
  EXPECT_EQ(testComponent(cast, HEALING_COMP), false);
  EXPECT_EQ(testComponent(cast, TELEPORT_COMP), false);
  EXPECT_EQ(testComponent(cast, CONDITIONS_COMP), false);
  EXPECT_EQ(testComponent(cast, RANGE_COMP), false);
  EXPECT_EQ(testComponent(cast, RICOCHET_COMP), true);
  EXPECT_EQ(getCastName(cast), "Acid Splash");
}