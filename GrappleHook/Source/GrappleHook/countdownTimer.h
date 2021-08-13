// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "countdownTimer.generated.h"

UCLASS()
class GRAPPLEHOOK_API AcountdownTimer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AcountdownTimer();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "time")
		int timeTotal;

	UPROPERTY(BlueprintReadOnly)
			int seconds_display;

		UPROPERTY(BlueprintReadOnly)
			int minutes_display;
		UPROPERTY(BlueprintReadOnly)
			int timeLeft;
protected:
	// Called when the game starts or when spawned
	UFUNCTION()
	virtual void BeginPlay() override;

public:	
	// Called every frame
	UFUNCTION(BlueprintCallable)
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void onTimerEnd();

	FTimerHandle timerHandler;
};
