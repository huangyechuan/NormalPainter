#pragma once
#include "MeshUtils/MeshUtils.h"

using namespace mu;
using FBXNode = void;

class IFBXExporterContext
{
public:
    enum class Topology
    {
        Points,
        Lines,
        Triangles,
        Quads,
    };

    virtual void release() = 0;
    virtual bool clear() = 0;

    virtual bool createScene(const char *name) = 0;
    virtual bool write(const char *path, bool ascii) = 0;

    virtual FBXNode* getRootNode() = 0;
    virtual FBXNode* findNodeByName(const char *name) = 0;

    virtual FBXNode* addTransform(FBXNode *parent, const char *name, float3 t, quatf r, float3 s) = 0;
    virtual FBXNode* addMesh(FBXNode *parent, const char *name,
        float3 t, quatf r, float3 s,
        Topology topology, int num_indices, int num_vertices,
        const int indices[], const float3 points[], const float3 normals[], const float4 tangents[], const float2 uv[], const float4 colors[],
        Weights4 weights[] = nullptr, FBXNode *bones[] = nullptr, float4x4 bindposes[] = nullptr, int num_bones = 0) = 0;

protected:
    virtual ~IFBXExporterContext() {}
};

npAPI IFBXExporterContext* CreateFBXExporter();