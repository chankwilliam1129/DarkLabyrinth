#include "sprite.hlsli"
Texture2D diffuse_map : register(t0);
SamplerState diffuse_map_sampler_state : register(s0);

cbuffer ConstantBuffer
{
    float4 light[4000];
    int light_count;
}

float4 main(VS_OUT pin) : SV_TARGET
{
    pin.pos.y *= 1920.0f / 1080.0f;
    float light_color = 0;
    for (int i = 0;i < light_count;i++)
    {
        float3 dir = light[i].xyz - pin.pos.xyz;
        if (light[i].w > 0)
        {
            float len = length(dir) / light[i].w;
            light_color += saturate(1.0f / (0.001f + 0.001f * len + 0.00003 * len * len));
        }
    }
    if (light_color > 1.0f)light_color = 1.0f;
    pin.color.xyz *= light_color;
    pin.color.w = pin.color.xyz / 5.0f;
    if (pin.color.w <= 0.1f)pin.color.w = 0.0f;
    return diffuse_map.Sample(diffuse_map_sampler_state, pin.texcoord) * pin.color;
}