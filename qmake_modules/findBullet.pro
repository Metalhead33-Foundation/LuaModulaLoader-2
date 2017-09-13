# CONFIG(release, debug|release): LIBS += -lBulletSoftBody -lBulletDynamics -lBulletCollision -lBullet3OpenCL_clew -lBullet3Geometry -lBullet3Dynamics -lBullet3Common -lBullet3Collision -lBullet2FileLoader
# CONFIG(debug, debug|release): LIBS += -lBulletSoftBody -lBulletDynamics -lBulletCollision -lBullet3OpenCL_clew -lBullet3Geometry -lBullet3Dynamics -lBullet3Common -lBullet3Collision -lBullet2FileLoader

# We will want Bullet 3 - "-lBullet3OpenCL_clew -lBullet3Geometry -lBullet3Dynamics -lBullet3Common -lBullet3Collision" -
# because it has the potential to use the GPU (OpenCL) for calculations instead of the CPU.
# Normal Bullet 2 - "-lBulletSoftBody -lBulletDynamics -lBulletCollision" - always uses the CPU for calculations, though
# I did hear that the latest version of Bullet 2 supports CUDA, since CUDA is Nvidia-only, I'll just go with Bullet 3.

CONFIG(release, debug|release): LIBS += -lBullet3OpenCL_clew -lBullet3Geometry -lBullet3Dynamics -lBullet3Common -lBullet3Collision -lBullet2FileLoader
CONFIG(debug, debug|release): LIBS += -lBullet3OpenCL_clew -lBullet3Geometry -lBullet3Dynamics -lBullet3Common -lBullet3Collision -lBullet2FileLoader

INCLUDEPATH += "/usr/include/bullet"
DEPENDPATH += "/usr/include/bullet"

# Also, if you want to use Bullet3, don't forget to use headers from the directories Bullet3Geometry, Bullet3Dynamics, Bullet3Common, Bullet2FileLoader, Bullet3OpenCL and Bullet3Collision.
# For Bullet2 - which we are not going to use -, you need to include headers the folders BulletSoftBody, BulletDynamics and BulletCollision.
# Regardless of whether we use Bullet2 or 3, I think headers from LinearMath are a must.
