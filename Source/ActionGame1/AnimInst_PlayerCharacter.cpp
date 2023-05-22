// Fill out your copyright notice in the Description page of Project Settings.

#include "AnimInst_PlayerCharacter.h"

UAnimInst_PlayerCharacter::UAnimInst_PlayerCharacter()
{

}

void UAnimInst_PlayerCharacter::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	Init_IKFootRef();
}

void UAnimInst_PlayerCharacter::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	Tick_IKFoot();
}

void UAnimInst_PlayerCharacter::Init_IKFootRef()
{
	//! Get IKFoot Component from owner
	APawn* pOwner = TryGetPawnOwner();
	if (pOwner != nullptr)
	{
		UActorComponent* pActorComp = pOwner->GetComponentByClass(UCpt_FootIK::StaticClass());
		if (pActorComp != nullptr)
		{
			m_pIK_Foot_Ref = Cast<UCpt_FootIK>(pActorComp);
			if (m_pIK_Foot_Ref == nullptr)
			{
				UE_LOG(LogTemp, Warning, TEXT("IKFootRef is nullptr"));
			}
		}
	}
}

void UAnimInst_PlayerCharacter::Tick_IKFoot()
{
	if (m_pIK_Foot_Ref == nullptr) return;

	m_stIKAnimValue = m_pIK_Foot_Ref->GetIKAnimValue();
}
